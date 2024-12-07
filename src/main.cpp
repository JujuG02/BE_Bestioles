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
   Peureuse* pe = new Peureuse();
   Kamikaze* k = new Kamikaze();
   Prevoyante* p = new Prevoyante();


   for (int i = 1; i <= 1; ++i){
      Bestiole* c = julien->createCarapace(pe);
      c = julien->createYeuxCustom(c, 150, 1.0, 4, 10000, false, k);

      //Bestiole* c2 = julien->createCamouflageCustom(nullptr, 0, 1000, true, k);
      Bestiole* c2 = julien->createCamouflageCustom(nullptr, 0., 10000, false, g);
      c2 = julien->createNageoire(c2, g);
      //c = julien->createYeuxMB(c);
      //c = julien->createCamouflageMB(c);
      ecosysteme.getMilieu().addMember( c );
      ecosysteme.getMilieu().addMember( c2 );
   }

   ecosysteme.run();

   delete julien;
   delete pe;
   delete g;
   delete p;
   delete k;

   return 0;
}