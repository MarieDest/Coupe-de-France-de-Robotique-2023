
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor
const int pin_5V = 12;
const int pin_contact = 13;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int presqueUnTour = (float) stepsPerRevolution * 270.0/360.0;
void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(10);
  pinMode(pin_5V, OUTPUT);
  pinMode(pin_contact, INPUT_PULLUP);
  // initialize the serial port:
  Serial.begin(9600);
}
void loop() {
  digitalWrite(pin_5V,HIGH); //on met du 5V dans le pin 12
  do{
    delay(10);
  }while(!digitalRead(pin_contact));
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(presqueUnTour);
  delay(50000000000);

 
}
