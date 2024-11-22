#ifndef SENSOR_H
#define SENSOR_H

#include "Decorator.h"
#include <vector>

class Sensor : public Decorator {
    public:
        void draw() override;
};

#endif