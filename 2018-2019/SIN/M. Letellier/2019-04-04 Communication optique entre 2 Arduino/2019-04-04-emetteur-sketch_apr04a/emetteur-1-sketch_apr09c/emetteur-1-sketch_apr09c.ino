#define BROCHE 9
int message, duree_emission ;
void setup () {
  pinMode (BROCHE, OUTPUT);
}
void loop () {
  for (message = 1; message <= 10 ; message ++) {
    duree_emission = (100 * message + 10) ; digitalWrite (BROCHE, HIGH) ;
    delay (duree_emission) ;
    digitalWrite (BROCHE, LOW) ;
    delay (1000) ;
  }
}
