#ifndef SENSOR_H
#define SENSOR_H

#include "Decorator.h"
#include <vector>

class Sensor : public Decorator {
    private:
        float fov;
        float range;
        float directionProb;
    
    public:
        Sensor(Bestiole &b, float fov, float range, float directionProb);
        void draw(UImg &support, double x, double y, double orientation) override;
};

#endif