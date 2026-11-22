# References

1. Glowlogics, *IoT Projects Handbook*, Project 02: IoT Light Control via Mobile App, printed pages 4–5 of the supplied handbook. This repository follows its ESP8266 NodeMCU, Blynk IoT, D1 output and LED/220 Ω demonstration outline.
2. Blynk documentation: https://docs.blynk.io/
3. Blynk website: https://blynk.io/
4. ESP8266 Arduino Core documentation: https://arduino-esp8266.readthedocs.io/
5. PlatformIO documentation: https://docs.platformio.org/

## Implementation note

The supplied handbook mentions both a Digital Pin D1 datastream and a Virtual Pin V0 callback. This repository explicitly implements Virtual Pin V0 controlling physical D1, and documents that choice in [blynk-setup.md](blynk-setup.md).
