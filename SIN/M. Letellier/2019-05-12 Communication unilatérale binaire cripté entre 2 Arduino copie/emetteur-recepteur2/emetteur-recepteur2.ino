#define BROCHE 10

char password;
int getpassword = 0;

unsigned long duree_reception ;
int one_bit, message, counter, poids;

void setup() {
  Serial.begin(9600);
  pinMode(BROCHE, INPUT);

  pinMode(9, OUTPUT);
  Serial.println("Hello, send your message...");
}

void loop() {
  int one_bit, counter;
  int message;
  char charmessage;

  duree_reception = pulseIn (BROCHE, HIGH, 4000000);
  //  Serial.println(duree_reception);

//    while (getpassword == 0) {
//      Serial.println("Set a password");
//      delay(5000);
//      if (Serial.available()) {
//        Serial.println("Password set.");
//        password = Serial.read();
//        getpassword = !getpassword;
//      }
//    }
  if (Serial.available ()) {
    charmessage = Serial.read();
    Serial.print(charmessage);
    message = charmessage;
    digitalWrite (9, HIGH);
    delayMicroseconds (310 );
    digitalWrite (9, LOW);

    for (counter = 0; counter < 8; counter++) {
      one_bit = message % 2;
      delayMicroseconds (100 );
      digitalWrite (9, HIGH);

      if (one_bit == 1) {
        delayMicroseconds (210 );
        digitalWrite (9, LOW);
      } else {
        delayMicroseconds(110 );
        digitalWrite (9, LOW);
        delayMicroseconds(100 );
      }
      message = message / 2;

      if ((duree_reception / 100  / 1000) == 3) {
        message = 0 ;
        poids = 1 ;
        for (int i = 0 ; i < 8 ; i++) {
          duree_reception = pulseIn (BROCHE, HIGH, 4000000);
          //       Serial.println(duree_reception);
          one_bit = (duree_reception / 100  / 1000) - 1 ;
          message = (message + one_bit * poids) ;
          poids = (poids * 2) ;
        }
        Serial.print(char(message));
      }
    }
  }
}
