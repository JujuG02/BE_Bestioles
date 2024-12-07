#ifndef CARAPACE_H
#define CARAPACE_H

#include "Decorator.h"
#include "Bestiole.h"
#include <vector>

/*
* Cette classe hérite de Decorator et permet de décorer une bestiole avec une carapace.
* La carapace est un atout qui permet de réduire la probabilité de mort de la bestiole.
* Elle réduit également la vitesse de la bestiole.
*/

class Carapace : public Decorator {
    private:
        double deathCoeff; // Ce coefficient vient se multiplier au coefficient deathProbability lors d'une collision
        double speedCoeff; // Ce coefficient vient se multiplier au coefficient vitesse.
        static const double MIN_SPEED_COEFF; // Coefficient de vitesse minimal
        static const double MIN_DEATH_COEFF; // Coefficient de mort minimal
    
    public:
        Carapace(Bestiole &b, double deathCoeff, double speedCoeff);
        Carapace(Bestiole &b);
        Carapace(Carapace const &c);
        Carapace& operator=(Carapace const &c);
        Carapace* clone() const override;
        ~Carapace() override final;
        
        void draw(UImg & support, double x, double y, double orientation, T* couleur) override final;
        bool collision(double deathProbability) override final;
        bool jeTeVois(const Bestiole &b) const override final;
        double getHidingCoeff() const override final;  
};

#endif