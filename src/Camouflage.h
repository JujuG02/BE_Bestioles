#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Decorator.h"
#include <vector>
/*
* Cette classe hérite de Decorator et permet de décorer une bestiole avec un camouflage
* Le camouflage est un atout qui permet de réduire la probabilité que la bestiole soit vue par une autre
*/
class Camouflage : public Decorator {
    private:
        double hidingCoeff;  // Ce coefficient vient se multiplier à la probabilité de détection de la bestiole
        static const double MAX_HIDE; // Coefficient de camouflage maximal
        static const double MIN_HIDE; // Coefficient de camouflage minimal
        static const double DIV_COLOR; // Coefficient d'éclaircissement de la couleur (pour la méthode draw)
    
    public:
        Camouflage(Bestiole &b, double hidingCoeff);
        Camouflage(Bestiole &b);
        Camouflage(Camouflage const &c);
        Camouflage& operator=(Camouflage const &c);
        Camouflage* clone() const override;
        ~Camouflage() override final;
        
        void draw(UImg & support, double x, double y, double orientation, T* couleur) override final;
        bool collision(double deathProbability) override final;
        bool jeTeVois(const Bestiole &b) const override final;
        double getHidingCoeff() const override final;
};

#endif