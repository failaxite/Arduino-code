#include <Arduino.h>


int ledPin = 5;     // On renomme la broche 5 en "ledPin"
int analogPin = 0;  // Le potentiomètre est connecté à la broche analogue 0
int val = 0;        // la variable qui stocke la valeur lue est mise à 0


void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    int val = analogRead(A0);
    analogWrite(ledPin, val / 4); 
    Serial.println(val);
}