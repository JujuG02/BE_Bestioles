#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include "Kamikaze.h"
#include "Sensor.h"
#include "BestioleCreator.h"

#include <iostream>

using namespace std;

int main()
{

   Aquarium ecosysteme(640, 480, 30);

   BestioleCreator* julien = new BestioleCreator();
   
   Gregaire* g = new Gregaire();
   Peureuse* p = new Peureuse();
   Kamikaze* k = new Kamikaze();


   for (int i = 1; i <= 10; ++i){
      Bestiole* c = julien->createCarapace(p);
      //c = julien->createYeuxMB(c);
      c = julien->createCamouflageMB(c);
      ecosysteme.getMilieu().addMember( c );
   }
   
   
   
   for (int i = 1; i <= 5; ++i){
      Bestiole* d = julien->createYeux(p);
      ecosysteme.getMilieu().addMember( d );
   }
   

   ecosysteme.run();

   delete julien;
   delete g;
   delete p;
   delete k;

   return 0;
}