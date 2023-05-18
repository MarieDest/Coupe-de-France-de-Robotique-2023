//void setup() {
//  // put your setup code here, to run once:
//
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//
//}// programme pour d�tection pour 4 ultrasons. le code est pour une carte qui va s'occuper uniquement de la d�tection. (parce que arduino c'est pas fait pour du multithreading)
/*
 Name:   UltrasonNano.ino
 Created: 06/11/2021 11:09:40
 Author:  Marie
*/

#include "UltrasonDetection.h" 
//#include "Communication.h"


float dist = 0;
bool Decision = false;
int valeur_direction = 0;
void setup() {
  setupDetection();
  Serial.begin(57600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop() {
//  valeur_direction = Comm();
  dist = measureDistance4();//valeur_direction
  Decision = dashDecision(dist, THRESHOLD);
  SendSignal(Decision);
//  delay(50);
}
