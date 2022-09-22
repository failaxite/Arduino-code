#include <Arduino.h>

void setup() {
  // initialise la sortie digital 13 comme sortie.
    pinMode(5, OUTPUT);
    Serial.begin(9600);
}

// La fonction loop fonctionne sans jamais s'arréter.
void loop() {
    int entree=analogRead(0);
    int attente=map(entree,0,1023,1000,50);

  digitalWrite(5, HIGH);   // allume la LED lorsque la tension est la plus élevée.
  delay(attente);              // temps attente en fonction de la valeur de l'entrée
  digitalWrite(5, LOW);    // Eteint la LED lorsque la tension est à 0
  delay(attente);              // temps attente en fonction de la valeur de l'entrée
}