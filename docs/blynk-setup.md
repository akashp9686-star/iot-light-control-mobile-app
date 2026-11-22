# Blynk IoT Setup

## 1. Create a template and device

1. Register or sign in at [Blynk](https://blynk.io/).
2. Create a template for an ESP8266 device.
3. Record the Template ID and Template Name.
4. Create a device from the template and copy its Auth Token.
5. Store the values in local `config/config.h`; never commit or share the token.

## 2. Configure the datastream used by this firmware

This repository implements the callback:

```cpp
BLYNK_WRITE(V0)
```

Therefore, create a **Virtual Pin V0** datastream:
- Name: Light Control
- Pin: V0
- Data type: Integer
- Minimum: 0
- Maximum: 1
- Default: 0

## 3. Resolve the handbook's pin wording

The Glowlogics handbook Project 02 contains both of these instructions:
- Blynk setup: add a datastream of type Digital Pin, pin D1.
- Supplied Arduino code: receive the button state with `BLYNK_WRITE(V0)`.
- App setup: assign the Button widget to V0 (or D1).

A Blynk Virtual Pin (V0) and an ESP8266 physical pin (D1/GPIO5) are not the same thing. The firmware in this repository follows the handbook's supplied `BLYNK_WRITE(V0)` code. For this implementation, configure the app Button on Virtual Pin V0; the callback then writes the state to physical D1. Do not configure a separate hardware Digital Pin datastream and assume it will invoke `BLYNK_WRITE(V0)`.

If the course evaluator explicitly requires the Digital Pin D1 datastream method instead, the firmware and dashboard should be revised together to that method before submission.

## 4. Configure the mobile dashboard

1. Install Blynk IoT and sign in.
2. Open the created device dashboard.
3. Add a Button widget.
4. Assign it to the Light Control / V0 datastream.
5. Set its mode to **Switch** so it maintains ON/OFF state.

## 5. Verify

After firmware upload, confirm that the device appears online. Toggle the button and observe the LED on D1 and the Serial Monitor. Record the actual result and date in [testing.md](testing.md).

Blynk's interface may change. Consult the current [Blynk documentation](https://docs.blynk.io/) if labels differ.
