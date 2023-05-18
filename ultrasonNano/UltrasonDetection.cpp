// 
// 
// 

#include "UltrasonDetection.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial1(11, 12); // RX, TX//on informe le microcontrôleur que l'on utilise ses broches pour une connexion série


//mesure de distance pour ultrason 
float measureDistance(int echoPin, int trigPin) {
  int duration;
  int distance;
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);
	// Calculating the distance
	distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
	return distance;
}
// décision True ou False en fonction de la distance réelle et de la distance min voulue
bool dashDecision(float distance, float THRESHOLD) {
	if (distance <= THRESHOLD) {
		Serial.println("truc détecté");
    return true;
	}
	else {
	  return false;
	  
	}
}

// fonction de setup pour les pins trigger et echo des ultrasons
void setupDetection(){
  pinMode(trigPinG, OUTPUT);
  pinMode(echoPinG, INPUT);
  pinMode(trigPinD, OUTPUT);
  pinMode(echoPinD, INPUT);
  pinMode(trigPinAR, OUTPUT);
  pinMode(echoPinAR, INPUT);
  pinMode(trigPinAV, OUTPUT);
  pinMode(echoPinAV, INPUT);
  pinMode(trigPinAvG, OUTPUT);
  pinMode(echoPinAvG, INPUT);
  pinMode(trigPinAvD, OUTPUT);
  pinMode(echoPinAvD, INPUT);
  pinMode(Signal,OUTPUT);
  mySerial1.begin(9600);
}


// fonction qui mesure la distance pour les 4 ultrasons et renvoit le plus petit
float measureDistance4(){
  float distanceMin=0;
	float distanceAR, distanceAV, distanceG, distanceD,distanceAvD,distanceAvG = 0;
	distanceAR = measureDistance(echoPinAR, trigPinAR);
	distanceAV = measureDistance(echoPinAV, trigPinAV);
	distanceG = measureDistance(echoPinG, trigPinG);
	distanceD = measureDistance(echoPinD, trigPinD);
  distanceAvG = measureDistance(echoPinAvG, trigPinAvG); 
  distanceAvD = measureDistance(echoPinAvD, trigPinAvD); 
	distanceMin = DetDistMin(distanceAV, distanceD, distanceAR, distanceG,distanceAvD,distanceAvG);

Serial.println("   distAv =" + String(distanceAV) +  "   distAr =" + String(distanceAR) + "   distG =" + String(distanceG) +"   distD =" + String(distanceD)+"   distAvD =" + String(distanceAvD)+"   distAvG =" + String(distanceAvG));
//mySerial1.println("   distAv =" + String(distanceAV) +  "   distAr =" + String(distanceAR) + "   distG =" + String(distanceG) +"   distD =" + String(distanceD)+"   distAvD =" + String(distanceAvD)+"   distAvG =" + String(distanceAvG));

//Serial.println("distance min ="+String(distanceMin));
return distanceMin;
}


// détermination de la distance minimale entre les 6.
float DetDistMin(float distAV, float distD, float distAR, float distG,float distAvD,float distAvG) {
	float test = 999;
 //float dist[6] = {distAV, distAR,distD, distG, distAvD, distAvG}; 
 // for(int i = 0; i<6; i++){
   if(distAV> 0){
    test = min(test,distAV);
   }
   if(distAR>0){
    test = min(test,distAR);
   }
   if(distD>0){
    test = min(test,distD);
   }
   if(distG>0){
    test=min(test,distG);
   }
   if(distAvD>0){
    test = min(test,distAvD);
   }
   if(distAvG>0){
    test = min(test, distAvG);
   }
 // }
  if(test ==999){
    return -1;
  }else{
    return test;
  }
	
}

//verification de la distance ( les ultrasons peuvent renvoyer 0.00 si la cible est trop loin ou si les câbles sont mal branchés)
// cette fonction renvoit true si la distance n'est pas nulle
bool verifDistance(float distance) {
	if (distance > 0.0) {
		return true;
	}
	else {
		return false;
	}
}
// envoit un signal si on est trop proche
void SendSignal(bool decision) {
	if (decision) {
  // c'est un signal qui regarde les fronts montants donc on va lui en donner plein:
//  for(int i = 0; i<10; i++){
//    digitalWrite(Signal, HIGH);
//   delay(50);
//   digitalWrite(Signal, LOW);
//   delay(50);
//  }
	  digitalWrite(Signal, HIGH);
   

 //  Serial.print("signal envoyé");
	}
    
	else {
		digitalWrite(Signal, LOW);
	}
}
