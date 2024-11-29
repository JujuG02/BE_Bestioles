#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "BestioleCreator.h"
#include "Behavior.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   BestioleCreator* bc = new BestioleCreator();


   for ( int i = 1; i <= 20; ++i ) {
      Bestiole* b = bc->create(nullptr);
      ecosysteme.getMilieu().addMember( (*b) );
   }
   ecosysteme.run();


   return 0;

}
