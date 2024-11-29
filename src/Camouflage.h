#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Decorator.h"
#include <vector>

class Camouflage : public Decorator {
    private:
        double hidingCoeff;
        static const double MAX_HIDE;
        static const double MIN_HIDE;
    
    public:
        Camouflage(Bestiole &b, double hidingCoeff);
        Camouflage(Bestiole &b);
        void draw(UImg &support) override final;
};

#endif