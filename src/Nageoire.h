#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "Decorator.h"
#include <vector>

class Nageoire : public Decorator {
    private:
        double speedCoeff;
        static const double MAX_SPEED_COEFF;
    
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