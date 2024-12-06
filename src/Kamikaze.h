#ifndef KAMIKAZE_H
#define KAMIKAZE_H

#include "Behavior.h"
#include <vector>
#include <iostream>

class Bestiole;

class Kamikaze : public Behavior {
private:
    Bestiole* currentTarget; // Cible actuelle
public:
    void move(std::vector<Bestiole> &bestioleList, Bestiole &b) override;
    Behavior* clone() const override{
        return new Kamikaze(*this);
    };
};

#endif 
