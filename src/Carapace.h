#ifndef CARAPACE_H
#define CARAPACE_H

#include "Decorator.h"
#include "Bestiole.h"
#include <vector>


class Carapace : public Decorator {
    private:
        double deathCoeff;
        double speedCoeff;
        static const double MIN_SPEED_COEFF;
        static const double MIN_DEATH_COEFF;
    
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