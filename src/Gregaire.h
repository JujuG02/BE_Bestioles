#ifndef GREGAIRE_H
#define GREGAIRE_H

#include "Behavior.h"
#include <vector>
class Bestiole;

class Gregaire : public Behavior {
public:
    void move(std::vector<Bestiole> &bestioleList) override;
};

#endif
