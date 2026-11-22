# Testing and Verification

## Current status

The repository contains a firmware template and project documentation. No physical build or end-to-end test evidence has been supplied for this repository yet. Therefore, all hardware and cloud tests below remain **not yet verified**.

| Test | Expected result | Status |
|---|---|---|
| PlatformIO build | Firmware compiles successfully | Not yet verified |
| Firmware upload | NodeMCU accepts firmware | Not yet verified |
| Wi-Fi connection | Device joins configured network | Not yet verified |
| Blynk authentication | Device appears online | Not yet verified |
| Button ON | V0 value 1; D1 HIGH; LED illuminates | Not yet verified |
| Button OFF | V0 value 0; D1 LOW; LED turns off | Not yet verified |
| Reconnection | Output returns to safe LOW state | Not yet verified |
| Credential hygiene | No secrets committed | Review required |

## Build checks

Run from the repository root:

```bash
pio run
```

Upload only after a successful build:

```bash
pio run --target upload
pio device monitor
```

## Physical test procedure

1. Inspect the LED polarity and 220 Ω resistor connection.
2. Power the NodeMCU over USB.
3. Confirm Wi-Fi and Blynk connection messages.
4. Switch the Blynk button ON and observe the LED.
5. Switch it OFF and observe the LED.
6. Repeat after briefly disconnecting and restoring Wi-Fi.
7. Record actual results, date and any observed issue.

## Evidence to add

- [ ] Screenshot of Blynk template/datastream configuration (hide credentials).
- [ ] Screenshot of device dashboard with button.
- [ ] Genuine photograph of NodeMCU and LED wiring.
- [ ] Genuine photograph showing LED ON.
- [ ] Genuine photograph showing LED OFF.
- [ ] Build output or successful compilation record.
- [ ] Serial Monitor output with secrets omitted.

Do not change a status to Pass until the corresponding test has been performed. Never publish Wi-Fi passwords, Blynk Auth Tokens or private account details.
