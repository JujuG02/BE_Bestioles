#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Decorator.h"
#include <vector>

class Camouflage : public Decorator {
    public:
        void draw() override;
};

#endif