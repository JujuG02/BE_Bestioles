#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "Decorator.h"
#include <vector>

class Nageoire : public Decorator {
    private:
        float speedCoeff;
    
    public:
        Nageoire(Bestiole &b, float speedCoeff);
        void draw(UImg &support, double x, double y, double orientation) override;
};

#endif