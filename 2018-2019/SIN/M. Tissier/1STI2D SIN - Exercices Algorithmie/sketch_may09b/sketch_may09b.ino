#define SWITCH 4

int nombpassage = 0;
int oldSwitchState = 1;

void setup() {
  Serial.begin(9600);
  digitalWrite(SWITCH, HIGH);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {

  digitalWrite(2, HIGH);
  if (digitalRead(SWITCH) != oldSwitchState) {
    oldSwitchState = digitalRead(SWITCH);
    if (!oldSwitchState) {
      nombpassage++;
      if (nombpassage == 10) {
        nombpassage = 0;
        digitalWrite(2, LOW);
        delay(10000);
      }
      Serial.println(nombpassage);
      
    }
  }
  delay(100);
}
