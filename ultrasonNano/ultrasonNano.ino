// programme pour d�tection pour 4 ultrasons. le code est pour une carte qui va s'occuper uniquement de la d�tection. (parce que arduino c'est pas fait pour du multithreading)
/*
 Name:		UltrasonNano.ino
 Created:	06/11/2021 11:09:40
 Author:	Marie
*/

#include "UltrasonDetection.h" 


float dist = 0;
bool Decision = false;
void setup() {
	setupDetection();
	Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop() {
	dist = measureDistance4();
	Decision = dashDecision(dist, THRESHOLD);
	SendSignal(Decision);
	delay(500);
}
