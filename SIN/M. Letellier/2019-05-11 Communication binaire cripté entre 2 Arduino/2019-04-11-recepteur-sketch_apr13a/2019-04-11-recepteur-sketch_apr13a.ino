#define BROCHE 10
char password;
int getpassword = 0;

unsigned long duree_reception ;
int one_bit, message, counter, poids;

void setup() {
  pinMode(BROCHE, INPUT);
  Serial.begin(9600);
}

void loop() {

    while (getpassword == 0) {
    Serial.println("Set a password");
    delay(5000);
    if (Serial.available()) {
      Serial.println("Password set.");
      password = Serial.read();
      getpassword = !getpassword;
    }
  }
  
  duree_reception = pulseIn (BROCHE, HIGH, 4000000);
//  Serial.println(duree_reception);

  if ((duree_reception / 100*password/1000) == 3) {
    message = 0 ;
    poids = 1 ;
    for (int i = 0 ; i < 8 ; i++) {
      duree_reception = pulseIn (BROCHE, HIGH, 4000000);
//       Serial.println(duree_reception);
      one_bit = (duree_reception / 100*password/1000) - 1 ;
      message = (message + one_bit * poids) ;
      poids = (poids * 2) ;
    }
  Serial.print(char(message));  
  }
}
