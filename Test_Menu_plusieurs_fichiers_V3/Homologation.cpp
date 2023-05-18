// 
// 
// 

#include "Homologation.h"
#include "Tests.h"

void homologation_statique_ferme(){
  Gauche(360);
  delay(999999999);

}
void homologation_statique_ouvert(){

AvanceMM(1750);
Droite(180);
AvanceMM(1650);
delay(99999999999);

}
void homologation_dynamique() {
AvanceMM(1750);
Gauche(180);
AvanceMM(1650);
delay(99999999999);
}
