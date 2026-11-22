# Circuit Diagram and Pin Connections

This project documents two load options from the Glowlogics handbook: the low-voltage LED demonstration and a relay output option. They are alternatives; assemble and verify the option actually used.

## A. LED demonstration

```text
NodeMCU D1 (GPIO5) ── 220 Ω resistor ── LED anode (+)
                                             LED cathode (−) ── NodeMCU GND
```

| From | To |
|---|---|
| NodeMCU D1 (GPIO5) | 220 Ω resistor |
| Other end of resistor | LED anode (+) |
| LED cathode (−) | NodeMCU GND |

The resistor must be in series with the LED. Verify polarity before applying power.

## B. Relay option (only after checking the exact module)

| Relay module terminal | Controller connection described by handbook |
|---|---|
| IN | NodeMCU D1 (GPIO5) |
| GND | NodeMCU GND |
| VCC | Module-rated supply; handbook mentions 3V3 or Vin/5V depending on module |

Relay modules are not interchangeable. Before connection, check the module's coil voltage, logic input thresholds, active-high/active-low trigger, isolation design and supply requirements. Do not assume a module marked "5V relay" accepts 3.3V logic correctly.

**Mains safety:** This guide is not a mains wiring instruction. Do not connect household AC to a breadboard or exposed relay terminals. Mains switching must be designed, enclosed and installed by a qualified person with correctly rated components and protection. For student demonstration, use the LED circuit or a safe low-voltage load.

## Control mapping

- Mobile app datastream: Blynk Virtual Pin V0 (integer 0/1).
- Firmware callback: `BLYNK_WRITE(V0)`.
- Physical ESP8266 output: NodeMCU D1 (GPIO5).

V0 is a Blynk virtual datastream; D1 is a physical NodeMCU pin. They are not interchangeable identifiers.

## Evidence checklist

Add a genuine photograph of the assembled circuit and label the exact load option used. Do not use this text diagram or stock imagery as proof that hardware was assembled.
