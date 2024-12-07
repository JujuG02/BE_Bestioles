#ifndef SENSOR_H
#define SENSOR_H

#include "Decorator.h"
#include <vector>

class Sensor : public Decorator {
    private:
        static const double MAX_FOV;
        static const double MIN_FOV;
        static const double MAX_RANGE;
        static const double MIN_RANGE;
        static const double MAX_DETEC_PROB;
        static const double MIN_DETEC_PROB;


        double fov;
        double range;
        double detectionProb;
    
    public:
        Sensor(Bestiole &b, double range, double detectionProb, double fov = -1.0);
        Sensor(Bestiole &b, bool isYeux);
        Sensor(Sensor const &s); //might be useless
        Sensor& operator=(Sensor const &s); //might be useless
        Sensor* clone() const override; //might be useless
        ~Sensor() override final;

        void draw(UImg & support, double x, double y, double orientation, T* couleur) override final;
        bool collision(double deathProbability) override final;
        bool jeTeVois(const Bestiole &b) const override final;
        double getHidingCoeff() const override final;
};

#endif