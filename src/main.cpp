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

   Aquarium       ecosysteme( 1280, 720, 30 );

   BestioleCreator* julien = new BestioleCreator();
   
   Gregaire* g = new Gregaire();
   Peureuse* p = new Peureuse();
   Kamikaze* k = new Kamikaze();

   /*
   for ( int i = 1; i <= 5; ++i ){
      Bestiole* b = julien->createOreille((Behavior*)&p);
      b = julien->createCarapace(b, (Behavior*)&p);
      ecosysteme.getMilieu().addMember( b );
   }
   */
   for (int i = 1; i <= 10; ++i){
      Bestiole* c = julien->createCarapaceMB();
      //c = julien->createYeuxMB(c);
      c = julien->createCamouflageMB(c);
      ecosysteme.getMilieu().addMember( c );
   }
   
   
   
   for (int i = 1; i <= 5; ++i){
      Bestiole* d = julien->createYeuxMB();
      ecosysteme.getMilieu().addMember( d );
   }
   
  /*
   for (int i = 1; i <= 5; ++i){
      Bestiole* e = julien->createCarapaceMB();
      ecosysteme.getMilieu().addMember( e );

   }
   */
   

   ecosysteme.run();

   return 0;


}