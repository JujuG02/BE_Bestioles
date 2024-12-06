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

   for ( int i = 1; i <= 5; ++i ){
      Bestiole* b = julien->createOreille(g);
      ecosysteme.getMilieu().addMember( b );
   }

   for ( int i = 1; i <= 5; ++i ){
      Bestiole* b = julien->createOreilleCustom(nullptr, 100 , 1, 10000, false, p);
      ecosysteme.getMilieu().addMember( b );
   }

   ecosysteme.run();

   delete julien;
   delete g;
   delete p;

   return 0;
}