#define MOTOR 11
#define SWITCH 2

int oldSwitchState=0;
int motorSpeed=0;

void setup() {
  pinMode(11, OUTPUT);
}

void loop() {
if (digitalRead(SWITCH) != oldSwitchState) {
  oldSwitchState = digitalRead(2);
  if (digitalRead(SWITCH) == 1) {
    motorSpeed = motorSpeed + 85 ;
    if (motorSpeed > 255) {
      motorSpeed = 0;
    }
      
  analogWrite(MOTOR, motorSpeed);
  delay(100);
  }
}

}
