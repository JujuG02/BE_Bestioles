#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Prevoyante.h"
#include "Kamikaze.h"
#include "Sensor.h"
#include "BestioleCreator.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   BestioleCreator* julien = new BestioleCreator();
   
   Kamikaze* p = new Kamikaze();


   for ( int i = 1; i <= 2; ++i ){
      Bestiole* b = julien->createOreille(p);
      ecosysteme.getMilieu().addMember( b );
   }



   ecosysteme.run();

   delete julien;
   delete p;

   return 0;

}
