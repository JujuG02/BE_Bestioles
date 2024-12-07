#ifndef SENSOR_H
#define SENSOR_H

#include "Decorator.h"
#include <vector>

/*
* Cette classe hérite de Decorator et permet de décorer une bestiole avec un capteur.
* Le capteur est un atout permettant de détecter les autres bestioles dans un certain rayon, 
* ainsi qu'une certaine distance, le tout dépendant d'une probabilité de détection donnée.
* Le capteur peut être différencié par deux types : 
* - Les yeux, qui ont un champ de vision maximal de 180 degrés
* - Les oreilles, qui ont un champ de détéction à 360 degrés
*/

class Sensor : public Decorator {
    private:
        static const double MAX_FOV;        // Champ de vision maximal
        static const double MIN_FOV;        // Champ de vision minimal
        static const double MAX_RANGE;      // Portée maximale
        static const double MIN_RANGE;      // Portée minimale
        static const double MAX_DETEC_PROB; // Probabilité de détection maximale
        static const double MIN_DETEC_PROB; // Probabilité de détection minimale

        double fov; // Champ de vision (en radians)
        double range; // Portée du capteur
        double detectionProb; // Probabilité que la bestiole détecte une autre bestiole
    
    public:
        Sensor(Bestiole &b, double range, double detectionProb, double fov = -1.0);
        Sensor(Bestiole &b, bool isYeux);
        Sensor(Sensor const &s); 
        Sensor& operator=(Sensor const &s); 
        Sensor* clone() const override; 
        ~Sensor() override final;

        void draw(UImg & support, double x, double y, double orientation, T* couleur) override final;
        bool collision(double deathProbability) override final;
        bool jeTeVois(const Bestiole &b) const override final;
        double getHidingCoeff() const override final;
};

#endif