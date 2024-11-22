#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "Decorator.h"
#include <vector>

class Nageoire : public Decorator {
    public:
        void draw() override;
};

#endif