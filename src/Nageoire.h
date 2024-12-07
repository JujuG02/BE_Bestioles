#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "Decorator.h"
#include <vector>

/*
* Cette classe hérite de Decorator et permet de décorer une bestiole avec des nageoires.
* Les nageoires sont un atout permettant d'augmenter la vitesse de la bestiole
*/

class Nageoire : public Decorator {
    private:
        double speedCoeff;  // Ce coefficient vient se multiplier au coefficient vitesse.
        static const double MAX_SPEED_COEFF; // Coefficient de vitesse maximal
    
    public:
        Nageoire(Bestiole &b, double speedCoeff);
        Nageoire(Bestiole &b);
        Nageoire(Nageoire const &n);
        Nageoire& operator=(Nageoire const &n);
        Nageoire* clone() const override;
        ~Nageoire() override final;
        
        void draw(UImg & support, double x, double y, double orientation, T* couleur) override final;
        bool collision(double deathProbability) override final;
        bool jeTeVois(const Bestiole &b) const override final;
        double getHidingCoeff() const override final;
};

#endif