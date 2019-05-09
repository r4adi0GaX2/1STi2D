void setup()
{
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, INPUT);
}

void loop()
{
  digitalWrite(11, HIGH);
  digitalWrite(9, LOW);
  if (digitalRead(12) == HIGH) {
    delay(1000); // Wait for 1000 millisecond(s)
  }
  delay(5); // Wait for 5 millisecond(s)
  digitalWrite(11, LOW);
  digitalWrite(9, HIGH);
  if (digitalRead(12) == HIGH) {
    delay(1000); // Wait for 1000 millisecond(s)
  }
  delay(5); // Wait for 5 millisecond(s)
}
