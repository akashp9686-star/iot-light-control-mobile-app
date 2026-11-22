# Evaluator Guide — Project 02

## Project
IoT Light Control via Mobile App — ESP8266 NodeMCU controlled by Blynk IoT.

## What to review
- Firmware: `src/main.cpp`
- Build configuration: `platformio.ini`
- Safe configuration template: `config/config.example.h`
- Architecture, circuit and wiring: `docs/architecture.md`, `docs/circuit-diagram.md`, `docs/wiring.md`
- Blynk configuration: `docs/blynk-setup.md`
- Testing and known limitations: `docs/testing.md`, `docs/results.md`, `docs/limitations.md`, `docs/review-checklist.md`

## Reproducible software checks
1. Install PlatformIO.
2. Copy `config/config.example.h` to `config/config.h`.
3. Keep placeholder credentials for compilation; use private local Blynk and Wi-Fi credentials only for a real deployment.
4. Run `pio run`.
5. Follow the manual test plan in `tests/manual-test-plan.md` when hardware and a configured Blynk template are available.

The GitHub Actions workflow provides hosted firmware compilation evidence. Review the linked workflow badge and Actions history for the actual run result.

## Scope and evidence
The documented app command uses Blynk Virtual Pin V0 and the physical output is NodeMCU D1/GPIO5. The repository does not claim that the Blynk app, Wi-Fi connection, LED circuit or relay alternative has been physically tested. No genuine hardware photographs or Blynk dashboard screenshots have been supplied. Use the low-voltage LED demonstration for initial physical validation; mains appliance switching is outside the prototype's verified scope.

## Evaluator request
Please assess the repository's firmware, architecture, Blynk configuration instructions, circuit documentation and software build evidence. Please advise whether repository-based assessment is accepted and whether a physical demonstration or additional evidence is required.
