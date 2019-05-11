void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);

}

void loop() {
  int one_bit, counter;
  int message;
  
  if (Serial.available ()) {
    message = Serial.read ();
    Serial.print(message);
    digitalWrite (9, HIGH);
    delayMicroseconds (310);
    digitalWrite (9, LOW);
    
    for (counter = 0; counter < 8; counter++) {
      one_bit = message % 2;
      delayMicroseconds (100);
      digitalWrite (9, HIGH);q
      
      if (one_bit == 1) {
        delayMicroseconds (210);
        digitalWrite (9, LOW);
      } else {
        delayMicroseconds(110);
        digitalWrite (9, LOW);
        delayMicroseconds(100);
      }
      message = message / 2;
    }
  }

}
