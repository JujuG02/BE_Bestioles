#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Gregaire.h"
#include "Behavior.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   //BestioleCreator* julien = new BestioleCreator();
   Gregaire g;

   for ( int i = 1; i <= 20; ++i ){
      Bestiole* b = new Bestiole();
      b->setBehavior((Behavior&) g);
      ecosysteme.getMilieu().addMember( *b );
   }
   ecosysteme.run();

   return 0;

}
