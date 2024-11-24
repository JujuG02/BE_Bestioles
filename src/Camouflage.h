#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Decorator.h"
#include <vector>

class Camouflage : public Decorator {
    private:
        double hidingCoeff;
    
    public:
        Camouflage(Bestiole &b, double hidingCoeff);
        Camouflage(Bestiole &b);
        void draw(UImg &support, double x, double y, double orientation) override;
};

#endif