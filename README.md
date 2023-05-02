# [S23-16] 5G mmWave Up Down Converter FPGA Mezzanine Card
### Virginia Tech S23-16 Senior Design Team Repository

---
### PCB Design File Documentation
PCB design is in KiCad and all related files are located [here](S23-16_PCB).

<details>
<summary>Schematic Files</summary>

| File Name | Description |
| --- | --- |
| [S23-16_PCB.kicad_sch](S23-16_PCB/S23-16_PCB.kicad_sch) | Overall Top Level Schematic |
| [Upconverter.kicad_sch](S23-16_PCB/Upconverter.kicad_sch) | Upconverter Top Level Schematic |
| [sch1013.kicad_sch](S23-16_PCB/sch1013.kicad_sch) | ADMV1013 Upconverter Schematic |
| [schHMC1131.kicad_sch](S23-16_PCB/schHMC1131.kicad_sch) | HMC1131 Power Amplifier Schematic |
| [Downconverter.kicad_sch](S23-16_PCB/Downconverter.kicad_sch) | Downconverter Schematic |
| [Synthesizer.kicad_sch](S23-16_PCB/Synthesizer.kicad_sch) | Synthesizer Schematic |
| [FMC_plus.kicad_sch](S23-16_PCB/FMC_plus.kicad_sch) | Digital/Power Interface Schematic |

</details>

<details>
<summary>PCB Files</summary>

| File Name | Description |
| --- | --- |
| [S23-16_PCB.kicad_pcb](S23-16_PCB/S23-16_PCB.kicad_pcb) | PCB Layout |

All component footprint and 3D models are located [here](S23-16_PCB/S23_16_Library.pretty).

</details>

<details>
<summary>Fabrication Files</summary>

Gerber and Drill files are located [here](S23-16_PCB/Fab_Files/Gerber) and use the following naming conventions:

### Gerber Files
| File Name | Description |
| --- | --- |
| [S23-16_PCB-F_Cu.gtl](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-F_Cu.gtl) | Front Copper |
| [S23-16_PCB-In1.Cu.g2](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-In1_Cu.g2) | First Internal Copper |
| [S23-16_PCB-In2_Cu.g3](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-In2_Cu.g3) | Second Internal Copper |
| [S23-16_PCB-B_Cu.gbl](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-B_Cu.gbl) | Back Copper |
| [S23-16_PCB-F_Paste.gtp](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-F_Paste.gtp) | Front Solder Paste (for stencil manufacturing) |
| [S23-16_PCB-F_Silkscreen.gto](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-F_Silkscreen.gto) | Front Silkscreen |
| [S23-16_PCB-B_Silkscreen.gbo](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-B_Silkscreen.gbo) | Back Silkscreen |
| [S23-16_PCB-F_Mask.gts](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-F_Mask.gts) | Front Solder Mask |
| [S23-16_PCB-B_Mask.gbs](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-B_Mask.gbs) | Back Solder Mask |
| [S23-16_PCB-Edge_Cuts.gm1](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-Edge_Cuts.gm1) | Board Edge |

### Drill Files
| File Name | Description |
| --- | --- |
| [S23-16_PCB-NPTH.drl](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-NPTH.drl) | Non-plated Through Holes |
| [S23-16_PCB-PTH.drl](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-PTH.drl) | Plated Through Holes |
| [S23-16_PCB-front-in1.drl](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-front-in1.drl) | Blind Vias (optional fencing vias between layers 1&2) |

</details>

<details>
<summary>Bill of Materials</summary>

The BOM is located on our shared drive [here](https://docs.google.com/spreadsheets/d/1cGQh0S1Flq79aJkekWkryKJpKwCh67Sn/edit#gid=1397198774).

</details>

<details>
<summary>PCB Stackup</summary>

| Material | Thickness | Dielectric Constant | Loss Tangent |
| --- | --- | --- | --- |
| Copper | 1.4 mils (1 oz.) |
| RO4003C | 8 mils | 3.55 | 0.0027 |
| Copper | 1.4 mils (1 oz.) |
| Prepreg | ~40 mils | ~4 | ~0.02 |
| Copper | 1.4 mils (1 oz.) |
| RO4003C | 8 mils | 3.55 | 0.0027 |
| Copper | 1.4 mils (1 oz.) |
| **Total** | **62 mils** |

Note: Prepreg material is arbitrary, consult manufactuer.

</details>

<details>
<summary>Design Rules</summary>

### Copper
| Parameter | Distance |
| --- | --- |
| Minimum Clearance | 5 mils |
| Minimum Track Width | 8 mils | 
| Minimum Annular Ring Width (Vias) | 5 mils | 
| Minimum Via Diameter | 19 mils | 
| Copper to Hole Clearance | 5 mils | 
| Copper to Edge Clearance | 10 mils |

### Through Holes
| Parameter | Distance | 
| --- | --- |
| Minimum Through Hole Diameter | 9 mils | 
| Hole to Hole Clearance | 10 mils |

</details>

---
### Microcontroller Code Documentation

Microcontroller code is located [here](Mezzanine_Card_Microcontroller_Code.ino) and is written for use on the Arduino platform.
