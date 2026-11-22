# Blynk IoT Setup

## 1. Create a template

1. Register or sign in at [Blynk](https://blynk.io/).
2. Create a new template for an ESP8266 device.
3. Record the Template ID and Template Name shown by Blynk.

## 2. Create the datastream

This repository uses a **Virtual Pin V0** datastream:

- Name: Light Control
- Pin: V0
- Data type: Integer
- Minimum: 0
- Maximum: 1
- Default: 0

The handbook's setup section first mentions a Digital Pin D1 datastream, but the supplied code uses `BLYNK_WRITE(V0)`, and the app instructions permit V0 (or D1). This repository selects the Virtual Pin V0 method because it matches the callback implemented in the source code. Do not configure the button as a separate hardware Digital Pin datastream while using this V0 callback.

## 3. Create a device

1. Create a device from the template.
2. Copy its Auth Token.
3. Add the Template ID, Template Name and Auth Token to your local `config/config.h`.
4. Keep the token private and never commit the local configuration file.

## 4. Configure the mobile dashboard

1. Install the Blynk IoT app and sign in to the same account.
2. Open the created device.
3. Add a Button widget.
4. Assign it to the **Light Control / V0** datastream.
5. Set the button mode to **Switch** so it maintains ON/OFF state.

## 5. Verify

After uploading the firmware, confirm that the device appears online. Toggle the button and observe the LED and Serial Monitor. Record the actual result and date in the testing record.

Blynk's interface may change. If labels differ, use the current Blynk documentation linked in [references.md](references.md).
