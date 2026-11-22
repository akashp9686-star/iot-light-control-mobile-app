# Methodology

1. Assemble the low-voltage LED circuit with a 220 Ω series resistor between NodeMCU D1 (GPIO5) and the LED.
2. Create a Blynk template and a Virtual Pin V0 integer datastream with values 0 and 1.
3. Create a device and obtain its Auth Token.
4. Add Wi-Fi and Blynk credentials to a local, untracked `config/config.h`.
5. Build the firmware for the ESP8266 NodeMCU.
6. Upload the firmware and open the Serial Monitor at 115200 baud.
7. Confirm the device connects to Wi-Fi and Blynk.
8. Operate the mobile Button widget in Switch mode.
9. Observe whether the LED follows the requested state.
10. Record test date, firmware revision, observed behaviour and any errors.

## Firmware logic

The Blynk `BLYNK_WRITE(V0)` callback reads the incoming integer. A nonzero value sets D1 HIGH; zero sets D1 LOW. On Blynk reconnection, the firmware initializes the output to LOW and writes zero to V0 to request a known OFF state.
