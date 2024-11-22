#ifndef CARAPACE_H
#define CARAPACE_H

#include "Decorator.h"
#include <vector>

class Carapace : public Decorator {
    private:
        float deathCoeff;
        float speedCoeff;
    
    public:
        Carapace(float deathCoeff, float speedCoeff);
        void draw(UImg &support, double x, double y, double orientation) override;
};

#endif