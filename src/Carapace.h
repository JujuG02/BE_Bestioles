#ifndef CARAPACE_H
#define CARAPACE_H

#include "Decorator.h"
#include "Bestiole.h"
#include <vector>


class Carapace : public Decorator {
    private:
        double deathCoeff;
        double speedCoeff;
        static const double MAX_SPEED_COEFF;
        static const double MAX_DEATH_COEFF;
    
    public:
        Carapace(Bestiole &b, double deathCoeff, double speedCoeff);
        Carapace(Bestiole &b);
        void draw(UImg &support, double x, double y, double orientation) override;
        bool collision(double deathProbability);
};

#endif