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

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
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
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   Bestiole* clone() const override;

   void move(Milieu &monMilieu);

   void death();
   
   void setBehavior(Behavior &behavior);
   void setVitesse(double vitesse);
};


#endif
