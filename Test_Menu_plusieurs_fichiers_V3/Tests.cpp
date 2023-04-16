// 
// 
// 

#include "Tests.h"
#include <Arduino.h>
#include "Servo.h"
#include <Stepper.h>

Servo servo_bras; // création de l'objet "servo"
Servo servo_epaule; // création de l'objet "servo"
bool notInterrupted_moteur = true;
const int stepsPerRevolution = 2048;
int incomingByte ;      
char myStr[1000];
char value;
char time;
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
void lecture_Serial_Comm(){
  //serial comm en 9600
      Serial.print("I received: ");
      while (Serial.available() > 0) {
            
//         for (int i = 0; i < sizeof(myStr) - 1; i++)
//         {
//          incomingByte = Serial.read();
//           myStr[i]=incomingByte;
//           Serial.print(myStr[i]);
//        }

        value = Serial.read();
        
        if (value =='T'){
          while (value !='U'){
            value = Serial.read();
            time = value;
            if (value !='U'){
            Serial.print(time);
            }
          }
          Serial.println();
        }
      }


}
void Test_1M() 
{
  digitalWrite(45, HIGH);
  digitalWrite(47, HIGH); 
  digitalWrite(49, HIGH);
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(X_DIR_PIN, HIGH);
  digitalWrite(Y_DIR_PIN, LOW);
  digitalWrite(X_STEP_PIN, HIGH);
  digitalWrite(Y_STEP_PIN, HIGH);
  


	
	for (int i = 0; i <= 320000; i++)
	{ 
	  if(notInterrupted_moteur ){//digitalRead(21)==LOW
  		digitalWrite(X_STEP_PIN, HIGH);
  		digitalWrite(Y_STEP_PIN, HIGH);
  		delay(50);
  		digitalWrite(X_STEP_PIN, LOW);
  		digitalWrite(Y_STEP_PIN, LOW);
  	}else{

  	}
	}

	//delay(5000);
	//trajet dans l'autre sens dans l'autre sens

	//digitalWrite(X_DIR_PIN, LOW);
	//digitalWrite(Y_DIR_PIN, HIGH);
	//for (int i = 0; i <= 3200; i++)
	//{
	//	digitalWrite(X_STEP_PIN, HIGH);
	//	digitalWrite(Y_STEP_PIN, HIGH);
	//	delay(1);
	//	digitalWrite(X_STEP_PIN, LOW);
	//	digitalWrite(Y_STEP_PIN, LOW);
	//}
	//delay(99999999999);
}
void Test_360_degres()
{
	// tour dans un sens
	digitalWrite(X_DIR_PIN, HIGH);
	digitalWrite(Y_DIR_PIN, HIGH);

	for (int i = 0; i <= 3200; i++)
	{
		digitalWrite(X_STEP_PIN, HIGH);
		digitalWrite(Y_STEP_PIN, HIGH);
		delay(1);
		digitalWrite(X_STEP_PIN, LOW);
		digitalWrite(Y_STEP_PIN, LOW);
	}

	delay(5000);
	//trajet dans l'autre sens dans l'autre sens

	digitalWrite(X_DIR_PIN, LOW);
	digitalWrite(Y_DIR_PIN, HIGH);
	for (int i = 0; i <= 3200; i++)
	{
		digitalWrite(X_STEP_PIN, HIGH);
		digitalWrite(Y_STEP_PIN, HIGH);
		delay(1);
		digitalWrite(X_STEP_PIN, LOW);
		digitalWrite(Y_STEP_PIN, LOW);
	}digitalWrite(X_ENABLE_PIN, LOW);
 digitalWrite(X_ENABLE_PIN, LOW);
	delay(99999999999);
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
