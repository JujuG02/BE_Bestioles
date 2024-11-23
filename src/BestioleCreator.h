#ifndef _BESTIOLECREATOR_H_
#define _BESTIOLECREATOR_H_

#include "Creator.h"
#include "Decorator.h"
#include "Behavior.h"

class BestioleCreator : public Creator {
    public :
        Bestiole* create() const override;
        Bestiole* create(Bestiole *baseBestiole = nullptr,
                        const std::vector<std::string>& flags = {},
                        double fov = 0.0, 
                        double range = 0.0, 
                        double detectionProb = 0.0, 
                        double speedCoeff = 0.0,
                        double hidingCoeff = 0.0,
                        double deathCoeff = 0.0,
                        bool isMultipleBehavior = false,
                        int age = 0,
                        Behavior *b = nullptr) const;
};





#endif