#define LED 9
int message, duration_emission;
int incomingByte = 0; // for incoming serial data

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) { // read the incoming byte
    incomingByte = Serial.read();

    Serial.print("I received: "); // say what you got
    Serial.println(incomingByte, DEC); // print as an ASCII-encoded decimal

  message = incomingByte ;
    
    duration_emission = (80 * message);
    digitalWrite(LED, HIGH);
    delay(duration_emission);
    digitalWrite(LED, LOW);
    delay(150);
    
  }
}
