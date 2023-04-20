# S23-16_5G-mmWave-Up-Down-Converter-FPGA-Mezzanine-Card
### Virginia Tech S23-16 Senior Design Team Repository

---
### PCB Design File Documentation
PCB design is in KiCad and all related files are located [here](S23-16_PCB/).

<details>
<summary>Schematic Files</summary>

### Schematic Files

| File Name | Description |
| --- | --- |
| [S23-16_PCB.kicad_sch](S23-16_PCB/S23-16_PCB.kicad_sch) | Overall Top Level Schematic |
| [Upconverter.kicad_sch](S23-16_PCB/Upconverter.kicad_sch) | Upconverter Top Level Schematic |
| [sch1013.kicad_sch](S23-16_PCB/sch1013.kicad_sch) | ADMV1013 Upconverter Schematic |
| [schHMC1131.kicad_sch](S23-16_PCB/schHMC1131.kicad_sch) | HMC1131 Power Amplifier Schematic |
| [Downconverter.kicad_sch](S23-16_PCB/Downconverter.kicad_sch) | Downconverter Schematic |
| [Synthesizer.kicad_sch](S23-16_PCB/Synthesizer.kicad_sch) | Synthesizer Schematic |
| [FMC_plus.kicad_sch](S23-16_PCB/FMC_plus.kicad_sch) | Digital/Power Interface Schematic |


### 
</details>

<details>
<summary>PCB Files</summary>

### PCB Files
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
| [S23-16_PCB-In1.Cu.g2](S23-16_PCB/Fab_Files/Gerber/S23-16_PCB-In1.Cu.g2) | First Internal Copper |
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

---
### Microcontroller Code Documentation
