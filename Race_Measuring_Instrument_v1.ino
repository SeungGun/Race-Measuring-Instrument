/* Paps(Race) Measuring Instrument Using Arduino.  Made by Sin Seung Gun 
Version 1 : Basic Function
*/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Trig_Pin = 9;
int Echo_Pin = 8;
float current_time = 0;
float start_time = 0;
boolean SW = false;

void setup() {
  Serial.begin(9600);
  pinMode(Echo_Pin, INPUT);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(12, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Gangseo paps");
  lcd.setCursor(0, 1);
  lcd.print("Record:");
}

void loop() {

  if (digitalRead(2) == HIGH) {
    start_time = millis() / 1000.0 ;
    SW = !SW;
  }
}
while (digitalRead(2) == HIGH);
}
if (SW) {
  current_time = millis() / 1000.0 ;
  lcd.setCursor(8, 1);
  lcd.print(current_time - start_time);
  //  Serial.println(current_time - start_time);
}
digitalWrite(Trig_Pin, LOW);
digitalWrite(Echo_Pin, LOW);
delayMicroseconds(2);
digitalWrite(Trig_Pin, HIGH);
delayMicroseconds(10);
digitalWrite(Trig_Pin, LOW);

unsigned long duration = pulseIn(Echo_Pin, HIGH);
float distance = ((float)(340 * duration) / 10000) / 2;
if (distance < 10) {
  SW = false;
  digitalWrite(12, HIGH);
  current_time = millis() / 1000.0 ;

} else {
  digitalWrite(12, LOW);
}

delay(50);
}
