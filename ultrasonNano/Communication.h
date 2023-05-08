// Communication.h

#ifndef _Communication_h
#define _Communication_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif
void setupComm();
void setEtat(String Etat_Value);
int Comm();
int RecupMessage(String message);
void condition();

#endif
