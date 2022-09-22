#include <Arduino.h>

// Définition des broches et variables utilisées
int LED = 5;
// Rapport cyclique
int x; 

void setup() {
    pinMode(LED, OUTPUT);
}

void loop() {
    x = 0;

  // Allumer progressivement la LED (0 --> 255)
    while (x <= 255) {
    analogWrite(LED, x);
    delay(10);
    x = x + 1;
}

  // Eteindre progressivement la LED (255 --> 0)
    x = 255;
    while (x >= 0) {   

    analogWrite(LED, x);
    delay(10);
    x = x - 1;
    }

}