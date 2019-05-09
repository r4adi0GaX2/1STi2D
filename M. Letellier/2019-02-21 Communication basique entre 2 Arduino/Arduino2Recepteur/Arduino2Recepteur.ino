#define BROCHE 10
unsigned long duree_reception;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin (9600);
}

void loop()
{
  duree_reception = pulseIn(BROCHE, HIGH, 4000000);
  Serial.println (duree_reception / 100000);
}