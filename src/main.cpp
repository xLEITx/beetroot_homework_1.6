#include <Arduino.h>

constexpr u_int8_t LDR_PIN = 7;
constexpr u_int8_t DELAY = 100;
u_int16_t rawData;
u_int32_t milliVoltsData;


void setup() {
  Serial.begin(115200);
  delay(DELAY);
  pinMode(LDR_PIN, INPUT);
}

void loop() {
  rawData = analogRead(LDR_PIN);
  Serial.println(rawData);
  delay(DELAY);
}

