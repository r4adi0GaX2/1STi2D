int i = 0;

int duree_emission = 0;

int message = 0;

void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  for (message = 1; message <= 10; message += 1) {
    // commentaire utile d'une seule ligne ici
    duree_emission = (100 * message + 10);
    // Production d'une impulsion
    digitalWrite(9, HIGH);
    delay(duree_emission); // Wait for duree_emission millisecond(s)
    digitalWrite(9, LOW);
    // Délai avant message suivant
    delay(1000); // Wait for 1000 millisecond(s)
  }
}
