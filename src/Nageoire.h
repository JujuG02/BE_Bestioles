#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "Decorator.h"
#include <vector>

class Nageoire : public Decorator {
    private:
        double speedCoeff;
    
    public:
        Nageoire(Bestiole &b, double speedCoeff);
        void draw(UImg &support, double x, double y, double orientation) override;
};

#endif