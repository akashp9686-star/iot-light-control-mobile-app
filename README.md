# IoT Light Control via Mobile App

Control a low-voltage LED demonstration from the Blynk IoT mobile application using an ESP8266 NodeMCU. The firmware receives a Blynk Virtual Pin V0 command and switches the LED output connected to D1 (GPIO5).

> **Project status:** This repository contains a documented implementation and firmware template. The repository owner must configure Blynk and Wi-Fi credentials, build and upload the firmware, and verify the physical circuit before claiming a successful end-to-end test. No physical test evidence has been supplied yet.

## Project objective

Demonstrate remote IoT control of a physical output over the internet using an ESP8266 NodeMCU and Blynk IoT. The handbook permits an LED for a safe demonstration and describes a relay as an option for switching a real load.

## Features

- ESP8266 NodeMCU Wi-Fi connectivity
- Blynk IoT mobile dashboard control
- Blynk Virtual Pin V0 switch command
- Output on NodeMCU D1 (GPIO5)
- LED demonstration with a 220 Ω series resistor
- Serial status messages
- Credentials kept in a local, ignored configuration header

## Hardware

- ESP8266 NodeMCU development board
- LED
- 220 Ω resistor
- Breadboard and jumper wires
- Android or iOS phone with Blynk IoT app
- USB cable and suitable power source

A 5 V relay module is listed in the handbook as an alternative for real-load switching. This repository's default firmware and wiring guide are for the low-voltage LED demonstration, not mains appliances.

## Wiring — LED demonstration

| LED connection | NodeMCU |
|---|---|
| LED anode (+) through 220 Ω resistor | D1 (GPIO5) |
| LED cathode (−) | GND |

See [docs/wiring.md](docs/wiring.md).

## Blynk control mapping

This implementation uses a **Virtual Pin V0** datastream for the mobile Button widget. The firmware callback `BLYNK_WRITE(V0)` receives the button state and writes it to physical output D1.

The handbook's setup text mentions a Digital Pin D1 datastream, while its sample firmware uses `BLYNK_WRITE(V0)` and the app instructions say V0 (or D1). To avoid mixing two different Blynk approaches, this repository consistently implements Virtual Pin V0.

## Repository structure

```text
.
├── README.md
├── platformio.ini
├── config/
│   └── config.example.h
├── src/
│   └── main.cpp
├── docs/
│   ├── abstract.md
│   ├── objectives.md
│   ├── components.md
│   ├── architecture.md
│   ├── wiring.md
│   ├── blynk-setup.md
│   ├── methodology.md
│   ├── testing.md
│   ├── limitations.md
│   └── references.md
├── tests/
│   └── manual-test-plan.md
├── images/
│   └── README.md
├── .gitignore
└── LICENSE
```

## Software requirements

- PlatformIO (VS Code extension or PlatformIO Core)
- ESP8266 NodeMCU board support
- Blynk library compatible with the current Blynk IoT platform
- Blynk account and a configured template/device

## Configure

1. Copy `config/config.example.h` to `config/config.h`.
2. Fill in the Blynk Template ID, Template Name, Auth Token, Wi-Fi SSID and Wi-Fi password.
3. Keep the Blynk button datastream as Virtual Pin V0.
4. Confirm the LED is wired to D1 through a 220 Ω resistor.
5. Do not commit `config/config.h` or share your Auth Token.

## Build and upload

```bash
pio run
pio run --target upload
pio device monitor
```

Select the correct serial port and upload settings for your NodeMCU. The firmware uses 115200 baud for serial output.

## Testing status

The code and documentation are prepared, but physical verification has not yet been recorded. Follow [docs/testing.md](docs/testing.md) and [tests/manual-test-plan.md](tests/manual-test-plan.md). Do not mark tests complete until they have actually been performed.

## Safety

Use the LED demonstration for evaluation and initial testing. Do not connect household mains wiring to a breadboard or exposed relay contacts. Any mains appliance installation must be designed and installed by a qualified person using an appropriately rated, isolated enclosure and protective measures.

## References

See [docs/references.md](docs/references.md) and the [Glowlogics IoT Projects Handbook](https://www.glowlogics.com/) for the assigned project outline.

## License

MIT — see [LICENSE](LICENSE).
