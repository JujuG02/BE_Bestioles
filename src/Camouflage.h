#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Decorator.h"
#include <vector>

class Camouflage : public Decorator {
    private:
        double hidingCoeff;
        static const double MAX_HIDE;
        static const double MIN_HIDE;
        static const double DIV_COLOR;
    
    public:
        Camouflage(Bestiole &b, double hidingCoeff);
        Camouflage(Bestiole &b);
        Camouflage(Camouflage const &c);
        Camouflage& operator=(Camouflage const &c);
        Camouflage* clone() const override;
        ~Camouflage() override final;
        
        void draw(UImg & support, double x, double y, double orientation, T* couleur) override final;
        bool collision(double deathProbability);
        bool jeTeVois(const Bestiole &b) const override final;

        double getHidingCoeff() const;
};

#endif