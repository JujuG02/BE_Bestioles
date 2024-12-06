#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include "Clone.h"
#include "Behavior.h"

using namespace std;


class Milieu;


class Bestiole : public Clone
{

protected :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   static const int        MAX_AGE;
   static const int        MIN_AGE;

   static int              next;
   static int              simulationAge;

protected :
   int               identite;
   int               x, y;
   int               age;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

   Behavior        * behavior;
   bool            isMultipleBehavior;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   virtual ~Bestiole();                              // Destructeur
   Bestiole& operator=(const Bestiole &b);        // Operateur d'affectation
   void action( Milieu & monMilieu );
   void draw( UImg & support ); //put to virtual if all decorators draw are coded

   virtual bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   Bestiole* clone() const override;

   void move(Milieu &monMilieu);

   virtual bool collision(double deathProbability);
   bool deathByAge();
   
   void setBehavior(Behavior &behavior);
   Behavior* getRandomBehavior();
   void setVitesse(double vitesse);
   void setIsMultipleBehavior(bool isMultipleBehavior);
   void setOrientation(double orientation);
   void setAge(int age);

   bool isColliding(const Bestiole &b) const;

   int getX() const;
   int getY() const;
   double getCumulX() const;
   double getCumulY() const;
   double getOrientation() const;
   double getVitesse() const;
   int getIdentite() const;
   T* getCouleur() const;

   void setX(int x);
   void setY(int y);
   void setCumulX(double cumulX);
   void setCumulY(double cumulY);
   void setCouleur(T *couleur);

   virtual void PrintMemory(){
      std::cout<<"Bestiole "<<this<<std::endl;
   }
};

#endif
