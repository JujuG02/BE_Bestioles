#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Decorator.h"
#include <vector>

class Camouflage : public Decorator {
    private:
        float hidingCoeff;
    
    public:
        Camouflage(Bestiole &b, float hidingCoeff);
        void draw(UImg &support, double x, double y, double orientation) override;
};

#endif