#ifndef KAMIKAZE_H
#define KAMIKAZE_H

#include "Behavior.h"
#include <vector>
class Bestiole;

class Kamikaze : public Behavior {
public:
    void move(std::vector<Bestiole> &bestioleList) override;
};

#endif 