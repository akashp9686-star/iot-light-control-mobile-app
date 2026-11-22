# Components and Software

## Hardware — Glowlogics handbook inventory

| Component | Quantity | Purpose / handbook description |
|---|---:|---|
| ESP8266 NodeMCU | 1 | Wi-Fi microcontroller running Blynk firmware |
| 5V relay module | 1 | Switches AC/DC loads safely; opto-isolated recommended |
| LED + 220 Ω resistor | 1 | Safe demonstration without high voltage |
| Breadboard | 1 | Prototyping platform |
| Jumper wires | 5 | Connections |
| Android/iOS phone | 1 | Runs Blynk IoT app |

**Important distinction:** The handbook lists the relay module in the component inventory, while it provides separate wiring paths for the LED demonstration and relay-based real-appliance switching. The LED is the recommended low-voltage demonstration path in this repository. The repository does not assert that the relay has been assembled or tested.

## Software and services

- Arduino framework for ESP8266
- PlatformIO build environment
- Blynk IoT account, template and device
- Blynk mobile application
- Wi-Fi network with internet access

## Pin mapping used by this firmware

| Signal | Mapping |
|---|---|
| Blynk app datastream | Virtual Pin V0 |
| ESP8266 physical output | NodeMCU D1 |
| ESP8266 GPIO number | GPIO5 |

The handbook's setup text mentions a Digital Pin D1 datastream, but its supplied firmware callback is `BLYNK_WRITE(V0)`; the app setup also says V0 (or D1). The implementation here follows the supplied callback: configure the Button on Virtual Pin V0, which controls physical D1 in firmware.

## Electrical notes

- D1 maps to ESP8266 GPIO5.
- Connect the LED in series with the 220 Ω current-limiting resistor.
- Verify the relay's coil voltage, trigger polarity, isolation and input compatibility from its exact datasheet before use.
- Do not assume a relay module's VCC input or IN logic is identical across models.
- Do not switch mains loads on an exposed breadboard. Any mains installation requires a qualified person and appropriate enclosure and protection.
