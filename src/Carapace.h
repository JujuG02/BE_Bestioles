#ifndef CARAPACE_H
#define CARAPACE_H

#include "Decorator.h"
#include <vector>

class Carapace : public Decorator {
    public:
        void draw() override;
};

#endif