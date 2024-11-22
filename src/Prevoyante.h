#ifndef PROVOYANTE_H
#define PREVOYANTE_H

#include "Behavior.h"
#include <vector>
class Bestiole;

class Prevoyante : public Behavior {
public:
    void move(std::vector<Bestiole> &bestioleList) override;
};

#endif 
