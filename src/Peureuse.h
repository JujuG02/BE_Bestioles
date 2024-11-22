#ifndef PEUREUSE_H
#define PEUREUSE_H

#include "Behavior.h"
#include <vector>
class Bestiole;

class Peureuse : public Behavior {
public:
    void move(std::vector<Bestiole> &bestioleList) override;
};

#endif 
