// 
// 
// 

#include "Tests.h"
#include <Arduino.h>
#include "Servo.h"
#include <Stepper.h>
#include "Communication.h"

Servo servo_bras; // création de l'objet "servo"
Servo servo_epaule; // création de l'objet "servo"
bool notInterrupted_moteur = true;
const int stepsPerRevolution = 2048;
const float Nb_pas_pour_1M = 10869.0;
const float Nb_pas_pour_360deg = 11420.0;

// Câblage:
// Broche 10 à IN1 sur le pilote ULN2003
// Broche 8 à IN2 sur le pilote ULN2003
// Broche 11 à IN3 sur le pilote ULN2003
// Broche 9 à IN4 sur le pilote ULN2003

Stepper StepperRideau = Stepper ( stepsPerRevolution, 10, 11, 8, 9 ) ;

void setup_Moteur()
{
	pinMode(X_STEP_PIN, OUTPUT);
	pinMode(X_DIR_PIN, OUTPUT);
	pinMode(X_ENABLE_PIN, OUTPUT);
	pinMode(Y_STEP_PIN, OUTPUT);
	pinMode(Y_DIR_PIN, OUTPUT);
	pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(X_Y_SLEEP_PIN,OUTPUT);
  pinMode(X_Y_RESET_PIN,OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(47,OUTPUT);
  pinMode(49,OUTPUT);
	digitalWrite(X_ENABLE_PIN, LOW);
	digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(X_Y_SLEEP_PIN, HIGH);
  digitalWrite(X_Y_RESET_PIN, HIGH);	

   servo_bras.attach(39); // attache le servo au pin spécifié
  servo_epaule.attach(39); // attache le servo au pin spécifié
  StepperRideau.setSpeed(5);

}
void setInterruption(bool noInterrupt){
  notInterrupted_moteur = noInterrupt;
}

void Test_1M() 
{

 AvanceMM(1000);
 delay(99999999999);
}

void Test_360_degres()
{

  Droite(180);
  delay(5000);
  Gauche(180);
	delay(99999999999);
}
void AvanceMM(int Nb_mm){

// pour Nb_mm mm  X pas
  digitalWrite(45, HIGH);
  digitalWrite(47, HIGH); 
  digitalWrite(49, HIGH);
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(X_DIR_PIN, HIGH);
  digitalWrite(Y_DIR_PIN, LOW);
 // digitalWrite(X_STEP_PIN, HIGH);
 //digitalWrite(Y_STEP_PIN, HIGH);
  

int indice_stoped = 0;
boolean interruption_moteur = false;
float nb_mm= (float) Nb_mm;
int Nb_pas = nb_mm * Nb_pas_pour_1M *0.001;
Serial.println(" fonction AvanceMM avec pour parametre : Nb_mm = "+(String) Nb_mm);
Serial.println("Nb_pas = "+(String) Nb_pas);
  for (int i = 0; i <= Nb_pas; i++)
  { 

    if( notInterrupted_moteur){//digitalRead(21)==LOW   
      if(interruption_moteur){
        i = indice_stoped;
        interruption_moteur = false;
      }
      digitalWrite(X_STEP_PIN, HIGH);
      digitalWrite(Y_STEP_PIN, HIGH);
      delay(1);
      digitalWrite(X_STEP_PIN, LOW);
      digitalWrite(Y_STEP_PIN, LOW);
     //  Serial.println(i);
      
    }else{
      if(!interruption_moteur){
        indice_stoped = i;
        interruption_moteur = true;
      }else{
        delay(1);
        i = i-1;
      }
    }
  }
}
void ReculeMM(int Nb_mm){

// pour Nb_mm mm  X pas
  digitalWrite(45, HIGH);
  digitalWrite(47, HIGH); 
  digitalWrite(49, HIGH);
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(X_DIR_PIN, LOW);
  digitalWrite(Y_DIR_PIN, HIGH);
 // digitalWrite(X_STEP_PIN, HIGH);
 //digitalWrite(Y_STEP_PIN, HIGH);
  

int indice_stoped = 0;
boolean interruption_moteur = false;
float nb_mm= (float) Nb_mm;
int Nb_pas = nb_mm * Nb_pas_pour_1M *0.001;
Serial.println(" fonction ReculeMM avec pour parametre : Nb_mm = "+(String) Nb_mm);
Serial.println("Nb_pas = "+(String) Nb_pas);
  for (int i = 0; i <= Nb_pas; i++)
  { 

    if( notInterrupted_moteur){//digitalRead(21)==LOW   
      if(interruption_moteur){
        i = indice_stoped;
        interruption_moteur = false;
      }
      digitalWrite(X_STEP_PIN, HIGH);
      digitalWrite(Y_STEP_PIN, HIGH);
      delay(1);
      digitalWrite(X_STEP_PIN, LOW);
      digitalWrite(Y_STEP_PIN, LOW);
      //Serial.println(i);
      
    }else{
      if(!interruption_moteur){
        indice_stoped = i;
        interruption_moteur = true;
      }else{
        delay(1);
        i = i-1;
      }
    }
  }

}
void Droite(int degre){
  digitalWrite(45, HIGH);
  digitalWrite(47, HIGH); 
  digitalWrite(49, HIGH);
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(X_DIR_PIN, LOW);
  digitalWrite(Y_DIR_PIN, HIGH);
  float nb_deg = (float) degre;
  int nb_pas = nb_deg * Nb_pas_pour_360deg *(1.0/360.0);

  Serial.println(" fonction Droite(deg) avec pour parametre : degre = "+(String) degre);
  Serial.println("nb_pas = "+(String) nb_pas);
  for (int i = 0; i <= nb_pas; i++)
  {
    digitalWrite(X_STEP_PIN, HIGH);
    delay(1);
    digitalWrite(X_STEP_PIN, LOW);
  }

}
void Gauche(int degre){
  digitalWrite(45, HIGH);
  digitalWrite(47, HIGH); 
  digitalWrite(49, HIGH);
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(X_DIR_PIN, LOW);
  digitalWrite(Y_DIR_PIN, HIGH);
  float nb_deg = (float) degre;
  int nb_pas = nb_deg * Nb_pas_pour_360deg *(1.0/360.0);
  Serial.println(" fonction Gauche avec pour parametre : degre = "+(String) degre);
  Serial.println("nb_pas = "+(String) nb_pas);
  for (int i = 0; i <= nb_pas; i++)
  {
    digitalWrite(Y_STEP_PIN, HIGH);
    delay(1);
    digitalWrite(Y_STEP_PIN, LOW);
  }

}
void TestNull(){
//    servo_epaule.write(0); // demande au servo de se déplacer à cette position
//   delay(1000); // attend 1000 ms entre changement de position

//   servo_epaule.write(180); // demande au servo de se déplacer à cette position
//   delay(1000); // attend 1000 ms entre changement de position

//   servo_epaule.write(150); // demande au servo de se déplacer à cette position
//   delay(1000); // attend 1000 ms entre changement de position
//    servo_bras.write(0); // demande au servo de se déplacer à cette position
//   delay(1000); // attend 1000 ms entre changement de position

//   servo_bras.write(180); // demande au servo de se déplacer à cette position
//   delay(1000); // attend 1000 ms entre changement de position

//   servo_bras.write(150); // demande au servo de se déplacer à cette position
//   delay(1000); // attend 1000 ms entre changement de position

  StepperRideau.step(stepsPerRevolution);
  delay(500);
  StepperRideau.step(-stepsPerRevolution);
  delay(500);
}
