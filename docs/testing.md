# Testing and Verification

## Current status

Firmware compilation has passed in GitHub Actions using the example configuration. No physical build or end-to-end test evidence has been supplied for this repository. All hardware and cloud tests below remain **not yet verified**.

| Test | Expected result | Status |
|---|---|---|
| Automated PlatformIO build | Firmware compiles successfully in GitHub Actions | Passed — [workflow run](https://github.com/akashp9686-star/iot-light-control-mobile-app/actions/runs/44998543471) |
| Firmware upload | NodeMCU accepts firmware | Not yet verified |
| Wi-Fi connection | Device joins configured network | Not yet verified |
| Blynk authentication | Device appears online | Not yet verified |
| Dashboard mapping | Button sends 0/1 on Virtual Pin V0 | Not yet verified |
| Button ON | V0 callback sets D1 HIGH; LED illuminates | Not yet verified |
| Button OFF | V0 callback sets D1 LOW; LED turns off | Not yet verified |
| Relay inventory | Actual 5V relay module availability/model recorded | Not confirmed |
| Relay operation (if assembled) | Output switches only as intended and within module ratings | Not tested |
| Credential hygiene | No secrets committed | Review required |

## Build checks

From the repository root:

```bash
pio run
```

Only after a successful build:

```bash
pio run --target upload
pio device monitor
```

## LED physical test procedure

1. Inspect LED polarity and the 220 Ω series resistor.
2. Power the NodeMCU over USB.
3. Confirm Wi-Fi and Blynk connection messages.
4. Switch the Blynk Button ON and observe the LED.
5. Switch it OFF and observe the LED.
6. Repeat after a brief Wi-Fi interruption.
7. Record the actual results, date and any observed issue.

## Relay test procedure — only if the relay is actually assembled

1. Identify the exact relay module and read its datasheet.
2. Verify its coil supply, trigger polarity, input voltage compatibility and isolation.
3. Test the relay output with a safe low-voltage load only.
4. Do not connect mains appliances as part of this student breadboard test.
5. Record the actual result and photograph the setup.

## Evidence to add

- [ ] Screenshot of Blynk template/datastream configuration (hide credentials).
- [ ] Screenshot of device dashboard with Button on V0.
- [ ] Genuine photograph of NodeMCU and LED wiring.
- [ ] Genuine photograph showing LED ON.
- [ ] Genuine photograph showing LED OFF.
- [ ] Build output or successful compilation record.
- [ ] Serial Monitor output with secrets omitted.
- [ ] If applicable, photograph and model details of the actual relay module.

Do not mark a status Pass until the corresponding test has been performed. Never publish Wi-Fi passwords, Blynk Auth Tokens or private account details.
