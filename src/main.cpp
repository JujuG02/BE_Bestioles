#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include "Sensor.h"

#include <iostream>

using namespace std;

int main()
{
   Aquarium ecosysteme(640, 480, 30);

   Gregaire g;
   Peureuse p;
   Prevoyante pr;
   /*
   for (int i = 1; i <= 20; ++i) {
      Bestiole* b = new Bestiole();
      b->setBehavior((Behavior&) g);
      ecosysteme.getMilieu().addMember(b);
   }
   
   for (int i = 1; i <= 20; ++i) {
      Bestiole* b = new Bestiole();
      b->setBehavior((Behavior&) p);
      ecosysteme.getMilieu().addMember(b);
   }
   */
   for (int i = 1; i <= 20; ++i) {
      Bestiole* b = new Bestiole();
      b->setBehavior((Behavior&) pr);
      ecosysteme.getMilieu().addMember(b);
   }

   ecosysteme.run();

   return 0;
}