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
        
        void draw(UImg &support) override final;
};

#endif