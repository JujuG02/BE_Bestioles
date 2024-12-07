#include "Bestiole.h"

#include "Milieu.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"

#include <cstdlib>
#include <cmath>
#include <iostream>


const double      Bestiole::AFF_SIZE = 8.; 
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;
const int         Bestiole::MAX_AGE = 10000;
const int         Bestiole::MIN_AGE = 1000;

int               Bestiole::next = 0;
int               Bestiole::simulationAge = 0;


Bestiole::Bestiole( void )
{

   identite = ++next;

   //cout << "const Bestiole (" << identite << ") par defaut" << endl;

   age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
   x = y = 0;
   cumulX = cumulY = 0.;
   isMultipleBehavior = false;
   behavior = getRandomBehavior();
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

}


Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   //cout << "const Bestiole (" << identite << ") par copie" << endl;

   age = b.age;
   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   isMultipleBehavior = b.isMultipleBehavior;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );
   behavior = (b.behavior) ? b.behavior->clone() : nullptr;
}


Bestiole::~Bestiole()
{
   delete[] couleur;
   delete behavior;

   //cout << "dest Bestiole" << endl;

}

Bestiole &Bestiole::operator=(const Bestiole &b)
{
    if (this != &b) { // Self-assignment check
        // Free existing memory
        delete[] couleur;
        delete behavior;

        // Allocate and copy new memory
        couleur = new T[3];
        memcpy(couleur, b.couleur, 3 * sizeof(T));

        behavior = (b.behavior) ? b.behavior->clone() : nullptr;

        // Copy other members
        age = b.age;
        x = b.x;
        y = b.y;
        cumulX = cumulY = 0.;
        isMultipleBehavior = b.isMultipleBehavior;
        orientation = b.orientation;
        vitesse = b.vitesse;
    }

    return *this;
}



void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}

// Fonction exécutée par le mileu
void Bestiole::action( Milieu & monMilieu )
{
   this->move(monMilieu);
   bouge( monMilieu.getWidth(), monMilieu.getHeight() );
   simulationAge++;
}

// Affichage de la bestiole
void Bestiole::draw( UImg & support, double x, double y, double orientation, T* couleur )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois(const Bestiole & b) const
{
   // Par défaut, la bestiole ne voit rien.
   // Pour qu'elle puisse voir d'autres bestioles il lui faut des yeux ou oreilles (décorateurs)
   return false;
}

Bestiole* Bestiole::clone() const
{
   return new Bestiole( *this );
}

void Bestiole::move(Milieu &monMilieu)
{
   double changingBehaviorProb = 0.05;  // Probabilité que la bestiole change de comportement à chaque pas

   auto detectedVoisins = monMilieu.getVoisins(this);
   if(this->isMultipleBehavior){
      double randomValue = static_cast<double>(rand()) / RAND_MAX;
      if (randomValue < changingBehaviorProb) {
         this->setBehavior(*getRandomBehavior());
      }
   }
   
   this->behavior->move(detectedVoisins,*this);

}

bool Bestiole::deathByAge()
{
   if(this->age < simulationAge){
      cout<<"Bestiole "<<this->identite<<" is dead cause of age"<<endl;
      return true;
   }
   return false;
}

bool Bestiole::collision(double deathProbabilty)
{
   double randomValue = static_cast<double>(rand()) / RAND_MAX;
   if (randomValue < deathProbabilty) {
      cout<<"Bestiole "<<this->identite<<" is dead cause of collision"<<endl;
      return true;
   } else {
      orientation += M_PI;
      if (orientation > 2 * M_PI) {
         orientation -= 2 * M_PI;
      }
      return false;
   }
}

bool Bestiole::isColliding(const Bestiole &b) const{
   double dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return (dist <= AFF_SIZE);
}

void Bestiole::setBehavior(Behavior &behavior)
{
   delete this->behavior;
   this->behavior = &behavior;
}

void Bestiole::setVitesse(double vitesse)
{
   if(vitesse>MAX_VITESSE){
      this->vitesse = MAX_VITESSE;
   }
   else if(vitesse<=0){
      //std::cout << "Vitesse must be greater than 0" << std::endl;
   }
   else{
      this->vitesse = vitesse;
   }
}

void Bestiole::setIsMultipleBehavior(bool isMultipleBehavior)
{
   this->isMultipleBehavior = isMultipleBehavior;
}

Behavior* Bestiole::getRandomBehavior()
{
   int randomValue = rand() % 4;
   switch (randomValue) {
      case 0:
         return new Gregaire();
      case 1:
         return new Peureuse();
      case 2:
         return new Kamikaze();
      case 3:
         return new Prevoyante();
      default:
         return nullptr;
   }
}


void Bestiole::setOrientation(double orientation)
{
   this->orientation = orientation;
}

void Bestiole::setAge(int age)
{  
   //The MIN_AGE is for random generation 
   //so we consider that the age can be less than MIN_AGE when setting manually
   if(age>MAX_AGE){
      this->age = MAX_AGE;
   }else{
      this->age = age;
   }
}

int Bestiole::getX() const
{
   return x;
}

int Bestiole::getY() const
{
   return y;
}

double Bestiole::getOrientation() const
{
   return orientation;
}

double Bestiole::getVitesse() const
{
   return vitesse;
}

double Bestiole::getCumulX() const
{
   return cumulX;
}

double Bestiole::getCumulY() const
{
   return cumulY;
}

int Bestiole::getIdentite() const
{
   return identite;
}

T* Bestiole::getCouleur() const
{
   return couleur;
}

double Bestiole::getHidingCoeff() const
{
   return 1.0;
}

void Bestiole::setX(int x)
{
   this->x = x;
}

void Bestiole::setY(int y)
{
   this->y = y;
}

void Bestiole::setCumulX(double cumulX)
{
   this->cumulX = cumulX;
}

void Bestiole::setCumulY(double cumulY)
{
   this->cumulY = cumulY;
}

void Bestiole::setCouleur(T *couleur)
{
   delete[] this->couleur;
   this->couleur = couleur;
}
