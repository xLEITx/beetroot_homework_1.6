#include <Arduino.h>

constexpr u_int8_t LDR_PIN = 7;
constexpr u_int8_t DELAY = 100;
u_int16_t rawData;
u_int32_t calculatedData;
u_int32_t milliVoltsData;


void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("|RAW|Calc|Mill|Accu|");
  pinMode(LDR_PIN, INPUT);
}

void loop() {
  rawData = analogRead(LDR_PIN);
  calculatedData = ((uint32_t)rawData * 3100) / 4095;
  milliVoltsData = analogReadMilliVolts(LDR_PIN);
  Serial.print(rawData);
  Serial.print("|");
  Serial.print(calculatedData);
  Serial.print("|");
  Serial.print(milliVoltsData);
  Serial.println("|");
  delay(DELAY);
}

