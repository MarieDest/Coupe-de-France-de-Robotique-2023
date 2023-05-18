// UltrasonDetection.h

#ifndef _ULTRASONDETECTION_h
#define _ULTRASONDETECTION_h


#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif

#include <SoftwareSerial.h>

// avant =  (4,5)
//gauche =  (8,9)
//droite =  (6,7)
// arriere = (2,3)
//const int echoPin = 2; // attach pin D2 Arduino to pin Echo of HC-SR04
//const int trigPin = 3; //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPinG 9
#define echoPinD 7
#define echoPinAV 5
#define echoPinAR 3
#define trigPinG 8
#define trigPinD 6
#define trigPinAV 4
#define trigPinAR 2
#define Signal 13

// defines variables 
const int THRESHOLD = 30; //variable for the decision to stop or not 30cm

//defines methodes
float measureDistance(int, int);
bool dashDecision(float, float);
float measureDistance4();
void setupDetection();
void SendSignal(bool);
bool verifDistance(float);
float DetDistMin(float, float, float, float);

#endif
