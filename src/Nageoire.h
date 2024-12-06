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
        void draw(UImg &support, double x, double y, double orientation) override;
};

#endif