# IoT Light Control via Mobile App

[![Firmware build](https://github.com/akashp9686-star/iot-light-control-mobile-app/actions/workflows/firmware-build.yml/badge.svg)](https://github.com/akashp9686-star/iot-light-control-mobile-app/actions/workflows/firmware-build.yml)

Control a low-voltage LED demonstration from the Blynk IoT mobile application using an ESP8266 NodeMCU. The firmware receives a Blynk Virtual Pin V0 command and switches the output on NodeMCU D1 (GPIO5).

> **Project status:** This repository contains a documented firmware implementation and setup guide. The owner must configure Blynk and Wi-Fi credentials, build and upload the firmware, and verify the physical circuit before claiming successful operation. No physical test evidence has been supplied yet.

## Objective

Control a physical load wirelessly from the Blynk mobile app. The Glowlogics handbook describes an LED as the safe demonstration load and a relay for real appliances.

## Handbook component inventory

| Component | Handbook quantity | Role |
|---|---:|---|
| ESP8266 NodeMCU | 1 | Wi-Fi microcontroller |
| 5V relay module | 1 | Switching AC/DC loads; opto-isolated recommended |
| LED + 220 Ω resistor | 1 | Safe low-voltage demonstration |
| Breadboard | 1 | Prototyping |
| Jumper wires | 5 | Connections |
| Android/iOS phone | 1 | Blynk IoT app |

The relay is part of the handbook's listed component inventory. The LED wiring is the low-voltage demo path; relay wiring is the handbook's alternative for a real appliance. This repository does not claim that a relay has been physically connected or tested.

## Implemented control mapping

- Blynk mobile Button: Virtual Pin **V0**, switch mode, integer 0/1.
- Firmware callback: `BLYNK_WRITE(V0)`.
- Physical output: NodeMCU **D1 (GPIO5)**.

The handbook's setup text mentions a Digital Pin D1 datastream, while its sample firmware uses `BLYNK_WRITE(V0)` and its app instructions say V0 (or D1). The source code in the handbook supports the V0 callback method. This repository therefore uses V0 for the app datastream and D1 as the physical ESP8266 output. These are different pin namespaces and must not be confused.

## LED demonstration wiring

| LED connection | NodeMCU |
|---|---|
| Anode (+) through 220 Ω series resistor | D1 (GPIO5) |
| Cathode (−) | GND |

See [docs/wiring.md](docs/wiring.md).

## Relay alternative

The handbook lists a 5V relay module and gives D1 as its input, GND as common ground, and 3V3 or Vin (5V) as its supply depending on the module. Relay modules vary; verify the exact module's coil voltage, trigger polarity, isolation and ESP8266 input compatibility before connecting it. Do not connect mains wiring as part of an unsupervised prototype.

## Repository structure

```text
.
├── README.md
├── LICENSE
├── .gitignore
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
│   ├── circuit-diagram.md
│   ├── wiring.md
│   ├── blynk-setup.md
│   ├── methodology.md
│   ├── testing.md
│   ├── results.md
│   ├── limitations.md
│   ├── references.md
│   └── review-checklist.md
├── tests/
│   └── manual-test-plan.md
└── images/
    ├── circuit/
    ├── application/
    └── results/
```

## Configure

1. Copy `config/config.example.h` to `config/config.h`.
2. Fill in Blynk Template ID, Template Name, Auth Token, Wi-Fi SSID and password.
3. Configure the Blynk Button as a Switch on Virtual Pin V0.
4. Connect the LED through a 220 Ω resistor to D1 and GND.
5. Keep `config/config.h` private; it is ignored by Git.

## Build and upload

```bash
pio run
pio run --target upload
pio device monitor
```

Select the correct serial port. Serial output uses 115200 baud.

## Verification status

Firmware and documentation are prepared, but physical operation has not been independently verified. Follow [docs/testing.md](docs/testing.md), record actual observations in [docs/results.md](docs/results.md), and complete [docs/review-checklist.md](docs/review-checklist.md). Add genuine circuit photographs and dashboard screenshots in the relevant `images/` folders after testing.

## Safety

Use the LED demonstration for initial evaluation. Do not connect household mains wiring to a breadboard or exposed relay contacts. Any mains appliance installation must be designed and installed by a qualified person using an appropriately rated isolated enclosure and protective measures.

## References

See [docs/references.md](docs/references.md), [docs/verification-and-research.md](docs/verification-and-research.md), and the supplied Glowlogics IoT Projects Handbook, Project 02. A GitHub Actions workflow at `.github/workflows/firmware-build.yml` is configured to compile the firmware using the example configuration; check the Actions tab for its actual result.

## License

MIT — see [LICENSE](LICENSE).
