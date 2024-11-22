#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include <vector>
class Bestiole;

class Behavior {
public:
    virtual void move(std::vector<Bestiole> &bestioleList) = 0;
    virtual ~Behavior() = default;
};

#endif 
