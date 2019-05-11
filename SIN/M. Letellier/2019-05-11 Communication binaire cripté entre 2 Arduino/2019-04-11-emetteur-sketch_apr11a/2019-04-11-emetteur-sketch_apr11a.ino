char password;
int getpassword = 0;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  Serial.println("Hello, send your message...");
}

void loop() {
  int one_bit, counter;
  int message;
  char charmessage;

  while (getpassword == 0) {
    Serial.println("Set a password");
    delay(5000);
    if (Serial.available()) {
      Serial.println("Password set.");
      password = Serial.read();
      getpassword = !getpassword;
    }
  }
  if (Serial.available ()) {
    charmessage = Serial.read();
    Serial.print(charmessage);
    message = charmessage;
    digitalWrite (9, HIGH);
    delayMicroseconds (310*password);
    digitalWrite (9, LOW);

    for (counter = 0; counter < 8; counter++) {
      one_bit = message % 2;
      delayMicroseconds (100*password);
      digitalWrite (9, HIGH);

      if (one_bit == 1) {
        delayMicroseconds (210*password);
        digitalWrite (9, LOW);
      } else {
        delayMicroseconds(110*password);
        digitalWrite (9, LOW);
        delayMicroseconds(100*password);
      }
      message = message / 2;
    }
  }
}
