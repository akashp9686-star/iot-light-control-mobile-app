# System Architecture

## Data/control flow

```text
Blynk mobile Button (Virtual Pin V0)
              |
              v
         Blynk Cloud
              |
       Internet / Wi-Fi
              |
              v
      ESP8266 NodeMCU
       Blynk firmware
              |
        D1 (GPIO5)
              |
        220 Ω resistor
              |
             LED
              |
             GND
```

## Operation

1. The NodeMCU joins the configured Wi-Fi network.
2. The firmware authenticates the device with Blynk using its device Auth Token.
3. The user presses the Button widget in the mobile app.
4. Blynk sends the value 0 or 1 on Virtual Pin V0.
5. The `BLYNK_WRITE(V0)` callback receives the value.
6. The firmware sets D1 LOW or HIGH and prints the resulting state to Serial Monitor.

## Pin mapping

| Logical/physical signal | Mapping |
|---|---|
| Blynk command | Virtual Pin V0 |
| ESP8266 output | NodeMCU D1 |
| ESP8266 GPIO | GPIO5 |
