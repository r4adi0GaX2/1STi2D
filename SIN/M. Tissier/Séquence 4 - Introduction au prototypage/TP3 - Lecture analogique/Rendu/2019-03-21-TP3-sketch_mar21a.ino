#include <LiquidCrystal.h>
#define POTAR A7
LiquidCrystal lcd(16, 17, 18, 20, 21, 22, 23);
int pinState = 0;
int value = 0;
int oldValue = 0;

void setup() {
  DDRB = 255;
  pinMode(POTAR, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print(" Test");
}

void loop() {
  value = analogRead(POTAR);
  if (value != oldValue) {
    oldValue = value;
    lcd.clear();
    lcd.print(" " + String(value));
    if (value > 1023) {
      PORTB = 0b00000000;
    } else if (value > 895) {
      PORTB = 0b10000000;
    } else if (value > 767) {
      PORTB = 0b11000000;
    } else if (value > 639) {
      PORTB = 0b11100000;
    } else if (value > 511) {
      PORTB = 0b11110000;
    } else if (value > 383) {
      PORTB = 0b11111000;
    } else if (value > 255) {
      PORTB = 0b11111100;
    } else if (value > 127) {
      PORTB = 0b11111110;
    } else {
      PORTB = 0b11111111;
    }
  }
  delay(100);
}
