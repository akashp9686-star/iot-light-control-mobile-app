#include "config.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#ifndef BLYNK_TEMPLATE_ID
#error "Define BLYNK_TEMPLATE_ID in config/config.h"
#endif
#ifndef BLYNK_TEMPLATE_NAME
#error "Define BLYNK_TEMPLATE_NAME in config/config.h"
#endif
#ifndef BLYNK_AUTH_TOKEN
#error "Define BLYNK_AUTH_TOKEN in config/config.h"
#endif
#ifndef WIFI_SSID
#error "Define WIFI_SSID in config/config.h"
#endif
#ifndef WIFI_PASSWORD
#error "Define WIFI_PASSWORD in config/config.h"
#endif

// Handbook LED demo output: NodeMCU D1 = ESP8266 GPIO5.
constexpr uint8_t OUTPUT_PIN = D1;

// Blynk mobile Button widget sends 0/1 on Virtual Pin V0.
BLYNK_WRITE(V0) {
  const int requestedState = param.asInt();
  const bool outputOn = (requestedState != 0);

  digitalWrite(OUTPUT_PIN, outputOn ? HIGH : LOW);
  Serial.println(outputOn ? F("Output ON") : F("Output OFF"));
}

BLYNK_CONNECTED() {
  // Start in a known safe state after a cloud reconnect.
  digitalWrite(OUTPUT_PIN, LOW);
  Blynk.virtualWrite(V0, 0);
  Serial.println(F("Connected to Blynk"));
}

void setup() {
  Serial.begin(115200);
  pinMode(OUTPUT_PIN, OUTPUT);
  digitalWrite(OUTPUT_PIN, LOW);

  Serial.println();
  Serial.println(F("IoT Light Control - ESP8266"));

  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASSWORD);
}

void loop() {
  Blynk.run();
}
