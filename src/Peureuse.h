#ifndef PEUREUSE_H
#define PEUREUSE_H

#include "Behavior.h"
#include <vector>
class Bestiole;

class Peureuse : public Behavior {

public:
    Peureuse() {}
    void move(std::vector<Bestiole> &bestioleList, Bestiole& b) override;
    Peureuse* clone() const override { 
        return new Peureuse(*this); 
    }
};

#endif 
