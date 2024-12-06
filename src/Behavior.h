#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include <vector>

class Bestiole;

class Behavior {
public:
    virtual ~Behavior() = default;
    virtual void move(std::vector<Bestiole> &bestioleList, Bestiole &b) = 0;
    virtual Behavior* clone() const =0;
};

#endif 
