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
        double directionProb;
        static const double MAX_FOV;
        static const double MIN_FOV;
        static const double MAX_RANGE;
        static const double MIN_RANGE;
        static const double MAX_DETEC_PROB;
        static const double MIN_DETEC_PROB;
    
    public:
        Sensor(Bestiole &b, double range, double directionProb, double fov = -1.0);
        Sensor(Bestiole &b, bool isYeux);
        Sensor(Sensor const &s);
        Sensor& operator=(Sensor const &s);
        Sensor* clone() const override;

        void draw(UImg &support, double x, double y, double orientation) override;
        bool jeTeVois(const Bestiole &b) const override;
};

#endif