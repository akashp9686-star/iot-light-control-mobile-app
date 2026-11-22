# Technical Research and Verification Notes

This document separates facts supported by the project source and official documentation from tests that require a physical device.

## 1. Blynk control model

The firmware receives the app command with `BLYNK_WRITE(V0)` and reads it as an integer using `param.asInt()`. The callback then writes the requested state to the physical output pin.

Blynk documentation explicitly distinguishes Virtual Pins from physical GPIO pins: a virtual pin is a software data channel and has no physical representation. Firmware must map the virtual-pin event to a GPIO action. Therefore this repository's mapping is:

| Layer | Identifier |
|---|---|
| Blynk datastream | Virtual Pin V0 |
| Firmware handler | `BLYNK_WRITE(V0)` |
| NodeMCU board label | D1 |
| ESP8266 GPIO | GPIO5 |

Sources:
- Blynk, Virtual Pins: https://docs.blynk.io/en/blynk-library-firmware-api/virtual-pins
- Blynk, Using Virtual Pins to Control Physical Devices: https://docs.blynk.io/en/getting-started/using-virtual-pins-to-control-physical-devices

## 2. Reconnection behaviour

The `BLYNK_CONNECTED()` callback calls `Blynk.syncVirtual(V0)`. This asks Blynk to synchronize the latest server-side datastream value with the device, so the app's stored switch state can be reapplied through `BLYNK_WRITE(V0)` after a connection is restored.

This is documented behaviour; reconnection on the actual device still requires a runtime test.

Source:
- Blynk, Using Virtual Pins to Control Physical Devices: https://docs.blynk.io/en/getting-started/using-virtual-pins-to-control-physical-devices

## 3. Supported controller family

Blynk lists ESP8266 boards, including NodeMCU, among supported hardware for its library. This supports the selected controller family, but does not verify a specific board clone, wiring, power supply or firmware upload.

Source:
- Blynk, Supported Hardware: https://docs.blynk.io/en/getting-started/supported-boards

## 4. PlatformIO build target

The project's `platformio.ini` selects the Espressif 8266 platform, Arduino framework and `nodemcuv2` board environment. The repository includes a GitHub Actions workflow that creates a local configuration file from the example template and runs `pio run`.

**CI result: PASS.** The GitHub Actions run triggered by the latest repository update completed successfully. Its `platformio-build` job passed the configuration-copy step and the `pio run` firmware compilation step. This verifies that the source compiles in the hosted PlatformIO environment using the example configuration. It does not verify device upload, Wi-Fi credentials, Blynk account configuration, GPIO electrical behaviour, LED illumination or relay operation.

Workflow: https://github.com/akashp9686-star/iot-light-control-mobile-app/actions/workflows/firmware-build.yml

Source:
- PlatformIO documentation: https://docs.platformio.org/

## 5. Electrical design boundary

The low-voltage LED path is documented as D1 through a 220 Ω series resistor to the LED, with the LED return to GND. The relay alternative is intentionally conditional: module input thresholds, coil supply, active level and isolation vary by product. The exact relay part number and its datasheet must be checked before asserting compatibility.

Do not connect exposed mains wiring to a breadboard. Any mains switching installation requires a qualified person and a properly rated, enclosed assembly.

## 6. Evidence classification

| Item | What this repository can establish |
|---|---|
| Source mapping | Reviewed against source and Blynk documentation |
| Controller family | Listed as supported by Blynk |
| CI compilation | Can be established by a successful GitHub Actions run |
| Firmware upload | Requires a physical board |
| Wi-Fi/Blynk online state | Requires actual credentials and a running device |
| LED/relay switching | Requires actual circuit testing |
| Photographic evidence | Must come from the real project |

No physical test result or measured performance is claimed in this repository.
