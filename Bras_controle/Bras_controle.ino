
#include <Servo.h> 
#include <SoftwareSerial.h>
Servo servoA1;
Servo servoA2;
Servo servoA3;
Servo servoA4;
Servo servoA5;
Servo servoA6;
Servo servoA7;
SoftwareSerial mySerial(10,11);
int incomingByte = 0;
void setup()
{
    servoA1.attach(3); 
    servoA2.attach(4); 
    servoA3.attach(5); 
    servoA4.attach(6); 
    servoA5.attach(7); 
    servoA6.attach(8); 
    servoA7.attach(9); 
    Serial.begin(57600);
  //  Serial.println("PRET");
    mySerial.begin(9600);
   // demo2();
}

void loop()
{
   for (int position = 0; position <=180; position ++){ // on crée une variable position qui prend des valeurs entre 0 à 180 degrés
    controle_1_Servo(1,position);
   } 
   for (int position = 180; position >=0; position --){ // on crée une variable position qui prend des valeurs entre 0 à 180 degrés
    controle_1_Servo(1,position);
   }
//  if(comm() != 0){
//    Serial.println("received : "+incomingByte);
//    if(incomingByte == 30){
//      Serial.println("launching demo2");
//      demo2();
//    }
//  }
}
int comm(){
  if (mySerial.available()) {
    incomingByte = mySerial.read();
  }
  return incomingByte;
}
void demo(){
    for (int position = 0; position <=180; position ++){ // on crée une variable position qui prend des valeurs entre 0 à 180 degrés
        servoA1.write(position);  // le bras du servomoteur prend la position de la variable position
        servoA2.write(position);  
        servoA3.write(position);  
        servoA4.write(position);  
        servoA5.write(position);  
        servoA6.write(position);  
        servoA7.write(position);  
        delay(15);  // on attend 15 millisecondes
    }

    for (int position = 180; position >=0; position --){ // cette fois la variable position passe de 180 à 0°
        servoA1.write(position);  // le bras du servomoteur prend la position de la variable position
        servoA2.write(position);  
        servoA3.write(position);  
        servoA4.write(position);  
        servoA5.write(position);  
        servoA6.write(position);  
        servoA7.write(position);  
        delay(15);  // le bras du servomoteur prend la position de la variable position
    }
}
void demo2(){
   for (int I = 1; I <=7; I ++){
     for (int position = 0; position <=180; position ++){ // on crée une variable position qui prend des valeurs entre 0 à 180 degrés
        controle_1_Servo(I,position);
        delay(15);  // on attend 15 millisecondes
    }
   }
    for (int I = 1; I <=7; I ++){
     for (int position = 180; position >=0; position --){ // on crée une variable position qui prend des valeurs entre 0 à 180 degrés
        controle_1_Servo(I,position);
        delay(15);  // on attend 15 millisecondes
    }
   }

   
}
void controle_1_Servo(int num_servo,int valeur){
  if(num_servo == 1)servoA1.write(valeur);  
  if(num_servo == 2)servoA2.write(valeur);  
  if(num_servo == 3)servoA3.write(valeur);  
  if(num_servo == 4)servoA4.write(valeur);  
  if(num_servo == 5)servoA5.write(valeur);  
  if(num_servo == 6)servoA6.write(valeur);
  if(num_servo == 7)servoA7.write(valeur);  
}
void controle_Servos(int valeurA1 = -1,int valeurA2 = -1 ,int valeurA3 = -1,int valeurA4 = -1,int valeurA5 = -1,int valeurA6 = -1,int valeurA7 = -1){
        if(valeurA1 != -1 )servoA1.write(valeurA1);
        if(valeurA2 != -1 )servoA2.write(valeurA2);  
        if(valeurA3 != -1 )servoA3.write(valeurA3);  
        if(valeurA4 != -1 )servoA4.write(valeurA4);  
        if(valeurA5 != -1 )servoA5.write(valeurA5);  
        if(valeurA6 != -1 )servoA6.write(valeurA6);  
        if(valeurA7 != -1 )servoA7.write(valeurA7);  
}
