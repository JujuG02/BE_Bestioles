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
   Kamikaze p;
   

   for ( int i = 1; i <= 20; ++i ){
      Bestiole* b = julien->createOreille((Behavior*)&p);
      b = julien->createCarapace(b, (Behavior*)&p);
      ecosysteme.getMilieu().addMember( b );
   }
   ecosysteme.run();

   return 0;

}
