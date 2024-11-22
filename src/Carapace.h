#ifndef CARAPACE_H
#define CARAPACE_H

#include "Decorator.h"
#include "Bestiole.h"
#include <vector>


class Carapace : public Decorator {
    private:
        double deathCoeff;
        double speedCoeff;
    
    public:
        Carapace(Bestiole &b, double deathCoeff, double speedCoeff);
        void draw(UImg &support, double x, double y, double orientation) override;
};

#endif