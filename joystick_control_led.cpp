#include <Arduino.h>

const int VRyPin = A2;
const int SWPin  = 5;
const int VRxPin = A3;

int VRx = 0;        // valeur horizontal
int VRy = 0;        // valeur vertical
int SW = 0;         // valeur switch

void setup() {
Serial.begin(9600);
pinMode(5, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
}

void loop() {

VRx = analogRead(VRxPin);
VRy = analogRead(VRyPin);
  //SW = digitalRead(SWPin);

  // print les resultats des calculs
Serial.print("VRrx = ");
Serial.print(VRx);
Serial.print("\tVRry = ");
Serial.print(VRy);
Serial.print("\tSW = ");
Serial.println(SW);

analogWrite(5, VRx/4);
analogWrite(6, VRy/4);
}