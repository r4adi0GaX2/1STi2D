void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);

}

void loop() {
  int message, one_bit, counter;
  if (Serial.available ()) {
    char message = Serial.parseInt ();
          Serial.println(message);

    digitalWrite (9, HIGH);
    delay (310);
    digitalWrite (9, LOW);
    for (counter = 0; counter < 8; counter++) {
      one_bit = message % 2;
      delay (100);
      digitalWrite (9, HIGH);
      if (one_bit == 1) {
        delay (210);
        digitalWrite (9, LOW);
      } else {
        delay(110);
        digitalWrite (9, LOW);
        delay(100);
      }
      message = message / 2;
    }
  }

}
