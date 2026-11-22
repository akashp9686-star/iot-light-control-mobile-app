# Components and Software

## Hardware

| Component | Quantity | Purpose |
|---|---:|---|
| ESP8266 NodeMCU | 1 | Wi-Fi microcontroller running the firmware |
| LED | 1 | Low-voltage output indicator |
| 220 Ω resistor | 1 | Limits LED current |
| Breadboard | 1 | Prototype assembly |
| Jumper wires | 5 | Electrical connections |
| Android/iOS phone | 1 | Runs Blynk IoT dashboard |
| USB cable and suitable supply | 1 | Programming and board power |

The Glowlogics handbook also lists one 5 V relay module as an option for switching a real load. It is not required for the LED-only demonstration.

## Software and services

- Arduino framework for ESP8266
- PlatformIO build environment
- Blynk IoT account, template and device
- Blynk mobile application
- Wi-Fi network with internet access

## Notes

Check the exact NodeMCU board pin labels. D1 maps to ESP8266 GPIO5. The LED must be connected in series with the 220 Ω resistor; do not connect an LED directly across a GPIO and ground without current limiting.
