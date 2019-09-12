void setup() {
  pinMode (10, INPUT) ;
  pinMode (LED_BUILTIN, OUTPUT) ;
}
void loop() {
  digitalWrite (LED_BUILTIN, digitalRead (10)) ;
}
