#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include "Clone.h"
#include "Behavior.h"

using namespace std;


class Milieu;

/*
* Une Bestiole est l'entité principale de notre simulation.
* Elle est caractérisée par plusieurs attributs mentionnés plus bas.
* Elle peut aussi avoir des atouts grâce aux décorateurs : Camouflage, Carapace, Nageoire, et Sensor.
*/

class Bestiole : public Clone
{

protected :
   static const double     AFF_SIZE;      // Taille d'affichage d'une bestiole dans la fenêtre graphique
   static const double     MAX_VITESSE;   // Vitesse maximale d'une bestiole
   static const double     LIMITE_VUE;    // Distance de perception d'une bestiole
   static const int        MAX_AGE;       // Age maximal d'une bestiole
   static const int        MIN_AGE;       // Age minimal d'une bestiole

   static int              next;          // Identifiant du prochain objet a instancier
   static int              simulationAge; // Age de la simulation

protected :
   int               identite;            // Identifiant de la bestiole
   int               x, y;                // Coordonnées de la bestiole
   int               age;                 // Age de la bestiole
   double            cumulX, cumulY;
   double            orientation;         // Orientation de la bestiole en radians
   double            vitesse;             // Vitesse de la bestiole

   T               * couleur;

   Behavior        * behavior;            // Comportement de la bestiole
   bool            isMultipleBehavior;    // Vaut true si la bestiole a plusieurs comportements (changement aléatoire)

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   virtual ~Bestiole();                              // Destructeur
   Bestiole& operator=(const Bestiole &b);        // Operateur d'affectation
   void action( Milieu & monMilieu );
   virtual void draw( UImg & support, double x, double y, double orientation, T* couleur );

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
   virtual double getHidingCoeff() const;

   void setX(int x);
   void setY(int y);
   void setCumulX(double cumulX);
   void setCumulY(double cumulY);
   void setCouleur(T *couleur);
   double turn(double orientation);

   virtual void PrintMemory(){
      std::cout<<"Bestiole "<<this<<std::endl;
   }
};

#endif
