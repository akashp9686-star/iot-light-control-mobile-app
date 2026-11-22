# Wiring Guide — LED Demonstration

## Handbook LED circuit

| LED terminal | Connection |
|---|---|
| Anode (+) | NodeMCU D1 (GPIO5) through a 220 Ω series resistor |
| Cathode (−) | NodeMCU GND |

The resistor must be in series with the LED. The resistor may be placed between D1 and the LED anode, or between the LED cathode and GND, provided the circuit remains a series path.

## Connection checklist

- [ ] Identify D1 and GND using the NodeMCU board labels.
- [ ] Connect D1 to one end of the 220 Ω resistor.
- [ ] Connect the other resistor end to the LED anode (longer leg on a standard LED).
- [ ] Connect the LED cathode to GND.
- [ ] Check LED polarity and resistor placement before powering the board.
- [ ] Keep the demonstration at low voltage.

## Optional relay configuration

The handbook lists a 5 V relay module for switching a real appliance and gives ESP8266 D1 as the relay input, with relay VCC, GND and IN connections. Relay modules differ in supply, trigger polarity and input compatibility. Confirm the exact module specifications and logic-level requirements before connecting it.

**Mains warning:** Do not wire 220 V AC through an exposed breadboard or attempt an unsupervised mains installation. Any mains switching must be designed and installed by a qualified person using an appropriately rated, isolated enclosure and protective devices. The LED demonstration is the recommended evaluation configuration.

## Evidence

No physical circuit photograph has been supplied yet. Add genuine images of the assembled LED circuit when available; do not use illustrative images as evidence of your build.
