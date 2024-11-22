#include "BestioleCreator.h"

Bestiole* BestioleCreator::create() const {
    return new Bestiole();
}

Bestiole* BestioleCreator::create(Bestiole *baseBestiole, 
                 const std::string& flag, 
                 double fov, 
                 double range, 
                 double detectionProb, 
                 double speedCoeff,
                 double hidingCoeff,
                 double deathCoeff,
                 Behavior *b
                 ) const {
    Bestiole* res = nullptr;

    if(baseBestiole == nullptr)
        res = new Bestiole();
    else
        res = baseBestiole->clone();
    
    if(flag=="carapace")
        int i;
        //res = new Carapace(res, deathCoeff, speedCoeff);
    else if(flag=="camouflage")
        int i;
        //res = new Camouflage(res, hidingCoeff);
    else if(flag=="nageoire")
        int i;
        //res = new Nageoire(res, speedCoeff);
    else if(flag=="oreilles")
        int i;
        //res = new Sensor(res, range, detectionProb);
    else if(flag=="yeux")
        int i;
        //res = new Sensor(res, range, detectionProb, fov )
    
    if(b != nullptr)
        res->setBehavior(*b);
    return res;
}