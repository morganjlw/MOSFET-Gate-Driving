# Power MOSFET Gate Driving Design Analysis

MOSFET Gate Driving design is analyzed using theoretical calculations. 

This gate drive design is controlled by an isolated PWM output. Code for Arduino and Raspberry Pi implementations are provided.

## Basic Power MOSFET Application Topology

The following schematic illustrates an isolated PWM controlled power MOSFET circuit. 

![](https://github.com/morganjlw/MOSFET-Gate-Driving/blob/master/images/PwrMOSFETSchematic.JPG)

## MOSFET Gate Driving

Quickly turning on and off a MOSFET is achieved by quickly charging and discharging the gate. MOSFET input capacitance is described by the following equivalent circuit and corresponding equations. 

<img src="https://latex.codecogs.com/gif.latex?C_{iss}&space;=&space;C_{gs}&space;&plus;&space;\frac{C_{gd}C_{gs}}{C_{gd}&space;&plus;&space;C_{gs}}\approx&space;C_{gs}&space;&plus;&space;C_{gd}&space;\:[\mathrm{F}]\\&space;\indent&space;Q_{g}&space;=&space;V_{GS(th)}C_{iss}&space;\:[\mathrm{C}]\\&space;\indent&space;I_{Gate}&space;=&space;\frac{Q_{g}}{t_{d(on)}}&space;\:[\mathrm{A}]&space;\\" title="C_{iss} = C_{gs} + \frac{C_{gd}C_{gs}}{C_{gd} + C_{gs}}\approx C_{gs} + C_{gd} \:[\mathrm{F}]\\ \indent Q_{g} = V_{GS(th))}C_{iss} \:[\mathrm{C}]\\ \indent I_{Gate} = \frac{Q_{g}}{t_{d(on)}} \:[\mathrm{A}] \\" />

As an example, we will design a gate drive circuit for a low-side switch using the Internation Rectifier IRLZ24N.  

![](https://github.com/morganjlw/MOSFET-Gate-Driving/blob/master/images/IRLZ24N.gif)

Some relevant IRLZ24N performance figures are included below:

![](https://github.com/morganjlw/MOSFET-and-IGBT-Gate-Driving/blob/master/IRLZ24Ndatasheetfigures/figures1and2.JPG)

![](https://github.com/morganjlw/MOSFET-and-IGBT-Gate-Driving/blob/master/IRLZ24Ndatasheetfigures/figures3and4.JPG)

![](https://github.com/morganjlw/MOSFET-and-IGBT-Gate-Driving/blob/master/IRLZ24Ndatasheetfigures/figures5to8.JPG)

According to the component datasheet (vary depending on Drain-Source Voltage and other parameters):

<img src="https://latex.codecogs.com/gif.latex?C_{iss}&space;=&space;480&space;\:\mathrm{pf}&space;\\&space;\indent&space;Q_{g}&space;=&space;15&space;\:\mathrm{nC}&space;\\&space;\indent&space;V_{gs(th)}&space;=&space;10&space;\:\mathrm{V}&space;\\" title="C_{iss} = 480 \:\mathrm{pF} \\ \indent Q_{g} = 18 \:\mathrm{nC} \\ \indent V_{gs(th)} = 10 \:\mathrm{V} \\" />

Assuming we require the gate to charge in 20 ns, we can derive the gate drive current requirement:

<img src="https://latex.codecogs.com/gif.latex?\indent&space;I_{g}&space;=&space;\frac{18&space;\:\mathrm{nC}}{20\:\mathrm{ns}}&space;=&space;900\:\mathrm{mA}\\" title="\indent I_{g} = \frac{18 \:\mathrm{nC}}{20\:\mathrm{ns}} = 900\:\mathrm{mA}\\" />

## Totem-Pole Drives

Totem-Pole drive configurations consists of NPN and PNP transistors connected in series by their Emitters. 

![](https://github.com/morganjlw/MOSFET-and-IGBT-Gate-Driving/blob/master/images/totempoledrive.jpg)

## Aside - Gate Power Dissipation & Heatsink Calculations


