#include <SoftwareSerial.h>

int incomingByte = 0; // for incoming serial data

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() {
   if (Serial.available() > 0) {
    incomingByte = Serial.read();
    
    Serial.println(incomingByte, DEC);
    mySerial.write(incomingByte);
   }
    
}
