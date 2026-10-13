#include <Arduino.h>

constexpr u_int8_t LDR_PIN = 7;
constexpr u_int8_t DELAY = 100;
u_int16_t rawData;
u_int32_t calculatedData;
u_int32_t milliVoltsData;
u_int8_t accuracy;

void serialOutput(){
  Serial.print(rawData);
  Serial.print("|");
  Serial.print(calculatedData);
  Serial.print("|");
  Serial.print(milliVoltsData);
  Serial.print("|      ");
  Serial.print(accuracy);
  Serial.print("%");
  Serial.println("|");
}



void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println(" RAW|Calc|Mill|Accuracy|");
  pinMode(LDR_PIN, INPUT);
}

void loop() {
  rawData = analogRead(LDR_PIN);
  calculatedData = ((uint32_t)rawData * 3100) / 4095;
  milliVoltsData = analogReadMilliVolts(LDR_PIN);
  accuracy = ((milliVoltsData - calculatedData)*100)/milliVoltsData;
  serialOutput();
  delay(DELAY);
}

