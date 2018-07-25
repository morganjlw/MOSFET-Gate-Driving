# MOSFET and IGBT Gate Driving Design Analysis

MOSFET and IGBT Gate Driving design is analyzed using theoretical calculations and supported by simulations. 

This gate drive design is controlled by an isolated micerocontroller PWM output. Isolation is achieved using optocouplers.

Quickly turning on and off a MOSFET is achieved by quickly charging and discharging the gate. MOSFET input capacitance is described by the following equivalent circuit and corresponding equations. 

![](https://github.com/morganjlw/MOSFET-and-IGBT-Gate-Driving/blob/master/mosfet.JPG)

<img src="https://latex.codecogs.com/gif.latex?C_{iss}&space;=&space;C_{DS}&space;&plus;&space;\frac{C_{GD}C_{GS}}{C_{GD}&space;&plus;&space;C_{GS}}\approx&space;C_{DS}&space;&plus;&space;C_{GD}&space;\:[\mathrm{F}]\\&space;\indent&space;Q_{Gate}&space;=&space;V_{GS}C_{iss}&space;\:[\mathrm{C}]\\&space;\indent&space;P_{Gate}&space;=&space;V_{GS}Q_{Gate}&space;=&space;V_{GS}^{2}C_{iss}f_{switching}&space;\:[\mathrm{W}]\\&space;\indent&space;I_{Gate}&space;=&space;\frac{P_{Gate}}{V_{GS}}&space;\:[\mathrm{A}]\\" title="C_{iss} = C_{DS} + \frac{C_{GD}C_{GS}}{C_{GD} + C_{GS}}\approx C_{DS} + C_{GD} \:[\mathrm{F}]\\ \indent Q_{Gate} = V_{GS}C_{iss} \:[\mathrm{C}]\\ \indent P_{Gate} = V_{GS}Q_{Gate} = V_{GS}^{2}C_{iss}f_{switching} \:[\mathrm{W}]\\ \indent I_{Gate} = \frac{P_{Gate}}{V_{GS}} \:[\mathrm{A}]\\" />

![](https://github.com/morganjlw/MOSFET-and-IGBT-Gate-Driving/blob/master/IRLZ24N.gif)

As an example, the Internation Rectifier IRLZ24N part datasheet shows that (though vary depending on Drain-Source Voltage and other parameters):

<img src="https://latex.codecogs.com/gif.latex?C_{iss}&space;=&space;480&space;\:\mathrm{pf}&space;\\&space;\indent&space;Q_{Gate}&space;=&space;15&space;\:\mathrm{nC}&space;\\&space;\indent&space;V_{GS-TH}&space;=&space;10&space;\:\mathrm{V}&space;\\" title="C_{iss} = 480 \:\mathrm{pf} \\ \indent Q_{Gate} = 15 \:\mathrm{nC} \\ \indent V_{GS-TH} = 10 \:\mathrm{V} \\" />

From this, we can derive the following Gate drive parameters:



Totem-pole drivers are first considered, though specialized integrated are readily available in the market. A totem-pole configuration consists of NPN and PNP transistors connected in series by their Emitters. 

![](https://github.com/morganjlw/MOSFET-and-IGBT-Gate-Driving/blob/master/totempoledrive.jpg)
