int dist = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(8, OUTPUT);
}

void loop()
{
  dist = 0.01723 * readUltrasonicDistance(6, 6);
  if (dist <= 10) {
    // Allumage fixe
    digitalWrite(8, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    if (dist > 200) {
      // Extinction
      digitalWrite(8, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
    } else {
      digitalWrite(8, HIGH);
      delay(500); // Wait for 500 millisecond(s)
      digitalWrite(8, LOW);
      delay(500); // Wait for 500 millisecond(s)
    }
  }
}