int swState = 0;
int ledState = 0;
unsigned long lastLedChange;

void setup() {
  Serial.begin(9600);
  digitalWrite(4, HIGH);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {

  if (millis() - lastLedChange > 2000) {
    lastLedChange = millis();
    digitalWrite(2, !digitalRead(2));
  }

  if (digitalRead(4) != swState) {
    swState = digitalRead(4);
    if (!swState) {
      ledState = !ledState;
      digitalWrite(3, ledState);
    }
  }
  delay(50);

}
