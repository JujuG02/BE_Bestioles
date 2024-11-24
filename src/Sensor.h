#ifndef SENSOR_H
#define SENSOR_H

#include "Decorator.h"
#include <vector>

class Sensor : public Decorator {
    private:
        double fov;
        double range;
        double directionProb;
    
    public:
        Sensor(Bestiole &b, double range, double directionProb, double fov = -1.0);
        Sensor(Bestiole &b, bool isYeux);
        void draw(UImg &support, double x, double y, double orientation) override;
};

#endif