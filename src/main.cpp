#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "BestioleCreator.h"
#include "Behavior.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Prevoyante.h"
#include "Kamikaze.h"
#include "Sensor.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   BestioleCreator* julien = new BestioleCreator();
   
   Kamikaze* p = new Kamikaze();
   

   for ( int i = 1; i <= 20; ++i ){
      Bestiole* b = julien->createOreille(p);
      b = julien->createCarapace(b, p);
      ecosysteme.getMilieu().addMember( b );
   }
   ecosysteme.run();

   delete julien;
   delete p;

   return 0;

}
