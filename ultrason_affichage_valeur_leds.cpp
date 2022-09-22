#include "Arduino.h"

#include "Ultrasonic.h"

#include <Adafruit_SSD1306.h>

#include <Wire.h>

#include <TM1637Display.h>

#include "pitches.h" 

#define CLK 6 // Pin du clock input
#define DIO 11 // Pin du data input/output

TM1637Display display = TM1637Display(CLK, DIO); // Creates display object that represents the TM1637 display


Ultrasonic ultrasonic(5, 3); // Trig et Echo

void setup() {
    display.clear(); // clear l'affichage
    display.setBrightness(7);
    Serial.begin(9600);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(12, OUTPUT);
}

void playPassed() { /* function playPassed */
  ////Play 'ON' Sound
    int melodyOn[] = {NOTE_C5, NOTE_C6, NOTE_D5, NOTE_A6};
    int durationOn = 200;
    for (int thisNote = 0; thisNote < 4; thisNote++) {
    tone(12, melodyOn[thisNote], durationOn);
    delay(200);
    }
}

void playFailed() { /* function playFailed */
  ////Play 'OFF' Sound
    nt melodyOff[] = {NOTE_C3, NOTE_D3};
    int durationOff = 200;
    for (int thisNote = 0; thisNote < 2; thisNote++) {
    tone(12, melodyOff[thisNote], durationOff);
    delay(200);
    }
}

void loop () {
    int dist = ultrasonic.distanceRead(CM);
    Serial.print(dist);
    Serial.println(" cm");

if (dist < 20) {
    digitalWrite(9, LOW); 
    digitalWrite(10, HIGH);
    playPassed();
    delay(1000);
    playFailed();
    delay(2000);
}
    if (dist > 20) {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
}
    delay(100);
    display.showNumberDec(dist); //affichage distance
}