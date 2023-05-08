#include <Arduino.h>
#include "Communication.h"
#include <SoftwareSerial.h>
int incomingByte ;      
char myStr[1000];
char value;
int i = 0;
char time;
int lastMessageIndex = 0;
String Message = "";
int idx0,idx1,idx2,idx3,idx4;
String distAvStr,distArStr,distGStr,distDStr;
int distAv,distAr,distG,distD;
SoftwareSerial mySerial(0, 1); // RX, TX//on informe le microcontrôleur que l'on utilise ses broches pour une connexion série


String keyWords[] = {"Av","Rec","G","D","Stop"};//Avance,Recule,Gauche,Droite et stop ( si stop tous les ultrasons sont actifs)
String Etat = "";
void setupComm(){
  Serial.begin(9600);
}
void setEtat(String Etat_Value){
  Etat = Etat_Value;
}

int Comm(){
   // check if data is available
  //Serial.println("comm activated"); 
  if (mySerial.available() > 0) {
      incomingByte = mySerial.read();
      myStr[i]=(char)incomingByte;
      Serial.println("Value comm available = "+ (String) incomingByte + "traduit par = "+ myStr[i]); 
      //Serial.print(myStr[i]);
      i = i+1;
      if(incomingByte == 13){//13 = retour chariot
        Message = "";
        for (int k = lastMessageIndex; k <=i; k++)
          { 
            Message = Message+myStr[k];
          }
        Serial.println("le message reçu est : "+Message);
        mySerial.println(Message + " OK");
        lastMessageIndex = i;
      }
      return RecupMessage(Message);
  }else{
    return 0;
  }
}
int RecupMessage(String message){
  int valeur_recue = 0;
  idx0=message.indexOf(keyWords[0]);
  idx1=message.indexOf(keyWords[1]);
  idx2=message.indexOf(keyWords[2]);
  idx3=message.indexOf(keyWords[3]);
  idx4=message.indexOf(keyWords[4]);

  if (idx0>=0){
    valeur_recue = 1;
  }
  if (idx1>=0){
    valeur_recue = 2;
  }
  if (idx2>=0){
    valeur_recue = 3;
  }
  if (idx3>=0){
    valeur_recue = 4;
  }
  if (idx4>=0){
    valeur_recue = 0;
  }
  return valeur_recue;
  //c'etait pour la V1 ou la carte principal recoit les infos (distAv = ? distAr = ? distG = ? distD = ?)
//        idx0=message.indexOf(keyWords[0]);
//        if(idx0>=0){
//          idx1=message.indexOf(keyWords[1]);
//          if(idx1>=0){
//            idx2=message.indexOf(keyWords[2]);
//            if(idx2>=0){
//              idx3=message.indexOf(keyWords[3]);
//              if(idx3>=0){
//                    distAvStr = message.substring(idx0+keyWords[0].length(),idx1);
//                    distArStr = message.substring(idx1+keyWords[1].length(),idx2);
//                    distGStr = message.substring(idx2+keyWords[2].length(),idx3);
//                    distDStr = message.substring(idx3+keyWords[3].length());
//                    //Serial.println("trouvé : "+(String)distAv+"  "+ (String)distAr+ "  "+(String)distG+"  "+(String)distD+"   ");
//                    distAv = distAvStr.toInt();
//                    distAr = distArStr.toInt();
//                    distG = distGStr.toInt();
//                    distD = distDStr.toInt();
//                }
//              }
//            }
//          }
//          condition();
}
     

//void condition(){
//   if(Etat == "Avance"){
//        if(distAv <30){
//          notInterrupted_moteur = true;
//        }else{
//          notInterrupted_moteur = false;
//        }
//      }
//}
