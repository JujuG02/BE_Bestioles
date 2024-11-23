#include "Milieu.h"

#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{
   double collidingDeathProb = 0.1;

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; )
   {
      for(auto jt = it + 1; jt != listeBestioles.end();){
         if(it->isColliding(*jt)){
            if(jt->collision(collidingDeathProb)){
               jt = listeBestioles.erase(jt);
            }
            else{
               ++jt;
            }
            if(it->collision(collidingDeathProb)){
               it = listeBestioles.erase(it);
               break;
            }
         } else {
            ++jt;
         }
      }
      if(it->deathByAge()){
         it = listeBestioles.erase(it);
      } 
      else {
         it->action( *this );
         it->draw( *this );
         ++it;
      }
   }
}

int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}

std::vector<Bestiole> Milieu::getVoisins(Bestiole & b)
{
    std::vector<Bestiole> voisins;
    for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         voisins.push_back(*it);
    return voisins;
}
