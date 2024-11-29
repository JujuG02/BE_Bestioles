#ifndef PREVOYANTE_H
#define PREVOYANTE_H

#include "Behavior.h"
#include <vector>
class Bestiole;

class Prevoyante : public Behavior {
public:
    void move(std::vector<Bestiole> &bestioleList, Bestiole& b) override;
    Prevoyante* clone() const override { 
        return new Prevoyante(*this); 
    }
};

#endif 
