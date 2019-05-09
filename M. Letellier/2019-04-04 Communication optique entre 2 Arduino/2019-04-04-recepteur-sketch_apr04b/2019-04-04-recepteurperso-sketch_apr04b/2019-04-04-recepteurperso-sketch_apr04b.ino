#define BROCHE 10
unsigned long duration_reception;
unsigned long error;

void setup() {
  pinMode(BROCHE, INPUT);
  Serial.begin(9600);
}
void loop() {
  duration_reception =
    pulseIn (BROCHE, HIGH, 4000000);
//    Serial.print("I received: ");
    Serial.println(duration_reception);
    duration_reception = duration_reception / 80 / 1000;
    char myChar = duration_reception;
    Serial.println(duration_reception);
    Serial.write(duration_reception);
//    error = (duration_reception / 80 / 1000) * 0,0241;
//    duration_reception = (duration_reception / 80 / 1000);
//    Serial.print("I calculate: ");
//    Serial.println(duration_reception);
//    duration_reception = duration_reception + error;
//    char myChar = duration_reception;
//    Serial.print("I correct: ");
//    Serial.println(duration_reception);
//    Serial.print("I give: ");
//   Serial.write(duration_reception);
}
//  else if ((duration_reception / 10 / 1000) <= 100) {
//    duration_reception = 97 * (duration_reception / 10 / 1000) / 95;
//    char myChar = duration_reception;
//    Serial.write(duration_reception);
//  }
//  else ((duration_reception / 10 / 1000) > 100); {
//    duration_reception = 161 * (duration_reception / 10 / 1000) / 158;
//    char myChar = duration_reception;
//    Serial.write(duration_reception);
//    {
//
//    }
//  }
