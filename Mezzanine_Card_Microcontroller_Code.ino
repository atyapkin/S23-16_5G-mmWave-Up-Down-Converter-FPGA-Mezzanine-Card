////////////////////////////////////////
// Filename: Microcontroller_FPGA     //
// Authors: Alex Rhee and Robert King //
// Date Created: 3/20/23              //
// Last Modified: 3/20/23             //
////////////////////////////////////////
#include <SPI.h>

// Needs more system checks
// Needs to read system for verification purposes
// Needs reading of system registers to properly flip bits, NVM
// Update to using defualt reset registers and overwriting

// System Defines
#define SYNTHESIZER 2               // Chip Select,   ACTIVE HIGH    
#define SYNTHESIZER_EN 3            // Enable Pin,    ACTIVE HIGH
#define OSCILLATOR_EN 4             // Enable Pin,    ACTIVE HIGH
#define UPCONVERTER 5               // Chip Select,   ACTIVE LOW
#define POWER_AMPLIFIER_EN 6        // Enable Pin,    ACTIVE HIGH     Controls HMC980 active bias controller which powers HMC1131
#define DOWNCONVERTER 7             // Chip Select,   ACTIVE LOW  
#define LOW_NOISE_AMPLIFIER_EN 8    // Enable Pin,    ACTIVE HIGH     Power Supply Enable Pin for 2.5V for downconverter   
#define DVDD_LINEAR_REG_EN 9        // Enable Pin,    ACTIVE HIGH     Power Supply Enable Pin for 1.8V rail for downconverter
#define DATAOUT 11                  // Data Out (MOSI)
#define DATAIN 12                   // Data In (MISO)
#define SCLK 13                     // System Clock

#define EVEN 0
#define ODD 1

bool _START_UP_ = true;

// SPI Transfer Settings
SPISettings upconverter(20000000, MSBFIRST, SPI_MODE0); // Writing Sample must be performed on the rising edge
SPISettings downconverter(20000000, MSBFIRST, SPI_MODE0);
SPISettings synthesizer(20000000, MSBFIRST, SPI_MODE0);


// SPI Data Transfer Variables
unsigned int RW;              // Read Write Bit (1)     Write = 0   Read = 1
unsigned int ADDR;            // Address Bits (6)
unsigned int DATA;            // Data Bits (16)
unsigned int P;               // Parity Bit (1)         odd parity

unsigned int toTransfer;

void setup()
{
  Serial.begin(115200); // Set Serial Communication Baud Rate to Arduino Maximum of 115200

  // Set digital pins to output or input
  pinMode(SYNTHESIZER, OUTPUT);
  pinMode(SYNTHESIZER_EN, OUTPUT);
  pinMode(OSCILLATOR_EN, OUTPUT);
  pinMode(UPCONVERTER, OUTPUT);
  pinMode(POWER_AMPLIFIER_EN, OUTPUT);
  pinMode(DOWNCONVERTER, OUTPUT);
  pinMode(LOW_NOISE_AMPLIFIER_EN, OUTPUT);
  pinMode(DVDD_LINEAR_REG_EN, OUTPUT);
  pinMode(DATAOUT, OUTPUT);
  pinMode(DATAIN, INPUT);
  pinMode(SCLK, OUTPUT);

  // Disable all chips on startup
  digitalWrite(SYNTHESIZER_EN, LOW);          //Disable synthesizer
  digitalWrite(OSCILLATOR_EN, LOW);           //Disable synthesizer oscillator
  digitalWrite(POWER_AMPLIFIER_EN, LOW);      //Disable power amplifier
  digitalWrite(LOW_NOISE_AMPLIFIER_EN, LOW);  //Disable 2.5V power rail
  digitalWrite(DVDD_LINEAR_REG_EN, LOW);      //Disable 1.8V power rail

  // Set Chip Selects to prevent unwatned communication
  digitalWrite(SYNTHESIZER, LOW); 
  digitalWrite(UPCONVERTER, HIGH); 
  digitalWrite(DOWNCONVERTER, HIGH); 

  while (!Serial); //Checks if Serial Monitor is open

  Serial.println("Setup Complete");
  SPI.begin();
  
}

void loop()
{
  if(_START_UP_ == true){
    Serial.println("Please press reset button located on the board to initiate startup sequence");
    Serial.println("Input 1 after reset button has pressed");
    _START_UP_ = false;
  }
  

  while(Serial.available() == 0){ // Do Nothing
  }

  int RST = Serial.parseInt();
  if(RST == 1){
    Serial.println("Starting SPI Communication startup protocol...");
    Serial.println("Initializing Upconverter Startup Sequence...");

    // synthesizer
    {
      digitalWrite(OSCILLATOR_EN, HIGH);          // Enable synthesizer oscillator
      digitalWrite(LOW_NOISE_AMPLIFIER_EN, HIGH); // Power up 2.5V rail
      digitalWrite(DVDD_LINEAR_REG_EN, HIGH);     // Power up 1.8V rail
      digitalWrite(SYNTHESIZER_EN, HIGH);         // Enable Synthesizer

      digitalWrite(SYNTHESIZER, HIGH) // Enable Writing to Synthesizer
      SPI.beginTransaction(synthesizer); // Set synthesizer SPI Settings

      // Synthesizer has no startup sequence

      SPI.endTransaction();
      digitalWrite(SYNTHESIZER, LOW); // Deselect ADMV1013 Chip, Active low enable
      
    }

    // Upconverter
    {
    
      digitalWrite(UPCONVERTER, LOW); // Select ADMV1013 Chip, Active low enable
      SPI.beginTransaction(upconverter); // Set Upconverter SPI Settings

      // Start up Sequence
      {
      RW = 0b0; // Write
      ADDR = 0b001010; // 0x0A
      DATA = 0xE700;
      toTransfer = (RW << 23)  | (ADDR << 17) | (DATA << 1); // Build Data without parity bit
      parity(ODD);
      data_monitor();
      SPI.transfer(toTransfer);
      clear();
      }

      // Baseband quadrature modulation (I/Q Mode)
      { 
      RW = 0b0; // Write
      ADDR = 0b000011; // 0x03
      readReg();
      DATA = DATA & 0xFF7F; // Set Bit 7 to 0
      toTransfer = (RW << 23)  | (ADDR << 17) | (DATA << 1); // Build Data without parity bit
      parity(ODD);
      data_monitor();
      SPI.transfer(toTransfer);
      clear()
      }

      // LO INPUT PATH Single Ended Mode
      {
      RW = 0b0; // Write
      ADDR = 0b001001; // 0x09
      DATA = DATA 0xE700; //set bits [9:6]
      Serial.print("Data: ");
      Serial.println(DATA, BIN);
      toTransfer = (RW << 23)  | (ADDR << 17) | (DATA << 1); // Build Data without parity bit
      parity(ODD);
      data_monitor();
      SPI.transfer(toTransfer);
      clear()

      SPI.endTransaction();
      digitalWrite(UPCONVERTER, HIGH); // Deselect ADMV1013 Chip, Active low enable

      digitalWrite(POWER_AMPLIFIER_EN, HIGH); // Turn on Power Amplifier
      }
    }

    // Down Converter
    {
      digitalWrite(DOWNCONVERTER, LOW) // Enable Writing to Downconverter
      SPI.beginTransaction(downconverter); // Set downconverter SPI Settings

      // Startup sequence 1
      {
      RW = 0b0; // Write
      ADDR = 0b001011; // 0x0B
      DATA = 0x727C;
      toTransfer = (RW << 23)  | (ADDR << 17) | (DATA << 1); // Build Data without parity bit
      parity(ODD);
      data_monitor();
      SPI.transfer(toTransfer);
      clear();
      }

      // Startup sequence 2
      {
      RW = 0b0; // Write
      ADDR = 0b000011; // 0x03
      readReg();
      DATA = DATA | 0x3000; // Set Bits [13:12] to 11
      toTransfer = (RW << 23)  | (ADDR << 17) | (DATA << 1); // Build Data without parity bit
      parity(ODD);
      data_monitor();
      SPI.transfer(toTransfer);
      clear();
      }



      SPI.endTransaction();
      digitalWrite(DOWNCONVERTER, HIGH); // Deselect ADMV1013 Chip, Active low enable
    }
  }

  

}

// NEEDS a read system that pulls data from register and populates the data tab
void readReg(){
  // TODO
  // Overwrite RW to read
  // Pull ADDR global variable
  // commit a transfer of readbit and addr
  // read returned data on MISO line
  // populate global variable of DATA with data from register
  // Swap RW back to write
  // end transcation
}


// Calculates parity bit and appends it to data
void parity(int parity_type){
  for(int bit = 0; bit < sizeof(toTransfer); bit++){
    P ^= (toTransfer & (1<<bit)) ? 1 : 0;
  }
  toTransfer = toTransfer | P;
}
  

// Clears the Data from the System
void clear(){
  RW = 0b0;
  ADDR = 0b000000;
  DATA = 0x0000;
  toTransfer = 0x000000;
}


// Prints Data to Serial Monitor
void data_monitor(){
  Serial.println("Outputting the follow data to System");
  Serial.print("Read / Write: ");
  String w = RW ? "Read" : "Write";
  Serial.println(w);

  Serial.print("Address: ");
  Serial.println(ADDR, HEX);

  Serial.print("Data: ");
  Serial.println(DATA, HEX);

  Serial.print("Parity: ");
  Serial.println(P, BIN);

  Serial.print("Message: ");
  Serial.println(toTransfer, BIN);
}
