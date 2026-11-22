# Wiring Guide — Project 02

The Glowlogics handbook provides two wiring paths: a low-voltage LED demonstration and a relay connection for a real appliance. They are alternatives for the controlled load; do not assume both are wired to the same output simultaneously.

## 1. LED demonstration (recommended for safe prototype testing)

| LED terminal | Connection |
|---|---|
| Anode (+) | NodeMCU D1 (GPIO5) through a 220 Ω series resistor |
| Cathode (−) | NodeMCU GND |

The resistor must be in series with the LED. Check polarity before powering the board.

## 2. Relay wiring (handbook alternative)

The handbook lists these connections:

| Relay pin | Handbook connection |
|---|---|
| IN | ESP8266 D1 (GPIO5) |
| VCC | ESP8266 3V3 or Vin (5V), depending on module |
| GND | ESP8266 GND |

**Hardware verification required:** Relay boards differ in coil voltage, trigger polarity, input circuitry and isolation. Check the exact relay module documentation before choosing its supply or connecting IN to an ESP8266 GPIO. Do not connect a 5V signal to an ESP8266 GPIO. The handbook's 3V3/Vin wording is not a substitute for checking the actual module's ratings.

## 3. Mains safety

The handbook mentions switching 220V AC through relay NO/COM terminals and warns against touching live wires. Do not attempt mains wiring on a breadboard or as an unsupervised student prototype. Any mains appliance installation must be designed and installed by a qualified person using a correctly rated, enclosed, isolated relay assembly and appropriate protection. The LED-only demonstration avoids this mains hazard.

## 4. Wiring checklist

- [ ] Identify NodeMCU D1 and GND from board labels.
- [ ] Connect LED anode through a 220 Ω resistor to D1.
- [ ] Connect LED cathode to GND.
- [ ] Check LED polarity and resistor placement.
- [ ] If using a relay instead, identify its exact model and verify coil voltage, input compatibility and trigger polarity.
- [ ] Keep mains wiring out of the student breadboard prototype.
- [ ] Photograph the actual circuit after assembly.

## Evidence

No physical circuit photograph has been supplied yet. Add genuine images of the actual assembled project when available. Do not use stock or generated images as proof of construction.
