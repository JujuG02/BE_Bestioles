#include "BestioleCreator.h"
#include "Carapace.h"
#include "Camouflage.h"
#include "Nageoire.h"
#include "Sensor.h"

Bestiole* BestioleCreator::create() const {
    return new Bestiole();
}

Bestiole* BestioleCreator::create(Bestiole *baseBestiole, 
                 const std::vector<std::string>& flags, 
                 double fov, 
                 double range, 
                 double detectionProb, 
                 double speedCoeff,
                 double hidingCoeff,
                 double deathCoeff,
                 bool isMultipleBehavior,
                 int age,
                 Behavior *b
                 ) const {
    Bestiole* res = nullptr;

    if(baseBestiole == nullptr)
        res = new Bestiole();
    else
        res = baseBestiole->clone();
    
    if(std::find(flags.begin(), flags.end(), "carapace") != flags.end())
        res = new Carapace(*res, deathCoeff, speedCoeff);
    if(std::find(flags.begin(), flags.end(), "camouflage") != flags.end())
        res = new Camouflage(*res, hidingCoeff);
    if(std::find(flags.begin(), flags.end(), "nageoire") != flags.end())
        res = new Nageoire(*res, speedCoeff);
    if(std::find(flags.begin(), flags.end(), "yeux") != flags.end())
        res = new Sensor(*res, range, detectionProb);
    if(std::find(flags.begin(), flags.end(), "yeux") != flags.end())
        res = new Sensor(*res, range, detectionProb, fov );
    
    if(isMultipleBehavior)
        res->setIsMultipleBehavior(isMultipleBehavior);
    
    if(age != 0)
        res->setAge(age);

    if(b != nullptr)
        res->setBehavior(*b);
    return res;
}