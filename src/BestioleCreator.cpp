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
    
    if(std::find(flags.begin(), flags.end(), "carapace") != flags.end()){
        if(deathCoeff==-1.0 || speedCoeff==-1.0)
            int i;//res= new Carapace(*res);
        else 
            res = new Carapace(*res, deathCoeff, speedCoeff);
    }
    if(std::find(flags.begin(), flags.end(), "camouflage") != flags.end()){
        if(hidingCoeff==-1.0)
            int i;//res = new Camouflage(*res);
        else 
            res = new Camouflage(*res, hidingCoeff);
    }
    if(std::find(flags.begin(), flags.end(), "nageoire") != flags.end()){
        if(speedCoeff == -1.0)
            int i;//res = new Nageoir(*res);
        else 
            res = new Nageoire(*res, speedCoeff);
    }
    if(std::find(flags.begin(), flags.end(), "oreille") != flags.end()){
        if(range == -1.0 || detectionProb == -1.0)
            int i;//res = new Sensor(*res, false);
        else 
            res = new Sensor(*res, range, detectionProb);
    }
    if(std::find(flags.begin(), flags.end(), "yeux") != flags.end()){
        if(range==-1.0 || detectionProb == -1.0 || fov == -1.0)
            int i;//res = new Sensor(*res, true)
        else 
            res = new Sensor(*res, range, detectionProb, fov );
    }
    
    res->setIsMultipleBehavior(isMultipleBehavior);
    
    if(age != -1)
        res->setAge(age);

    if(b != nullptr)
        res->setBehavior(*b);
    return res;
}

Bestiole* BestioleCreator::createNageoire(Bestiole *baseBestiole, Behavior *b) {
    return create(baseBestiole, {"nageoire"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createNageoire(Behavior *b) {
    return create(nullptr, {"nageoire"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createNageoireMB() {
    return create(nullptr, {"nageoire"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createNageoireMB(Bestiole *baseBestiole) {
    return create(baseBestiole, {"nageoire"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createNageoirCustom(Bestiole *baseBestiole, double speedCoeff, int age, bool isMultipleBehavior, Behavior *b) {
    return create(baseBestiole, {"nageoire"}, -1.0, -1.0, -1.0, speedCoeff, -1.0, -1.0, isMultipleBehavior, age, b);
}


Bestiole* BestioleCreator::createCarapace(Bestiole *baseBestiole, Behavior *b) {
    return create(baseBestiole, {"carapace"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createCarapace(Behavior *b) {
    return create(nullptr, {"carapace"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createCarapaceMB(Bestiole *baseBestiole) {
    return create(baseBestiole, {"carapace"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createCarapaceMB() {
    return create(nullptr, {"carapace"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createCarapaceCustom(Bestiole *baseBestiole, double deathCoeff, double speedCoeff, int age, bool isMultipleBehavior, Behavior *b) {
    return create(baseBestiole, {"carapace"}, -1.0, -1.0, -1.0, speedCoeff, -1.0, deathCoeff, isMultipleBehavior, age, b);
}


Bestiole* BestioleCreator::createCamouflage(Bestiole *baseBestiole, Behavior *b) {
    return create(baseBestiole, {"camouflage"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createCamouflage(Behavior *b) {
    return create(nullptr, {"camouflage"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createCamouflageMB(Bestiole *baseBestiole) {
    return create(baseBestiole, {"camouflage"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createCamouflageMB() {
    return create(nullptr, {"camouflage"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createCamouflageCustom(Bestiole *baseBestiole, double hidingCoeff, int age, bool isMultipleBehavior, Behavior *b) {
    return create(baseBestiole, {"camouflage"}, -1.0, -1.0, -1.0, -1.0, hidingCoeff, -1.0, isMultipleBehavior, age, b);
}


Bestiole* BestioleCreator::createOreille(Bestiole *baseBestiole, Behavior *b) {
    return create(baseBestiole, {"oreille"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createOreille(Behavior *b) {
    return create(nullptr, {"oreille"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createOreilleMB(Bestiole *baseBestiole) {
    return create(baseBestiole, {"oreille"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createOreilleMB() {
    return create(nullptr, {"oreille"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createOreilleCustom(Bestiole *baseBestiole, double range, double detectionProb, int age, bool isMultipleBehavior, Behavior *b) {
    return create(baseBestiole, {"oreille"}, range, detectionProb, -1.0, -1.0, -1.0, -1.0, isMultipleBehavior, age, b);
}


Bestiole* BestioleCreator::createYeux(Bestiole *baseBestiole, Behavior *b) {
    return create(baseBestiole, {"yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createYeux(Behavior *b) {
    return create(nullptr, {"yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createYeuxMB(Bestiole *baseBestiole) {
    return create(baseBestiole, {"yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createYeuxMB() {
    return create(nullptr, {"yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createYeuxCustom(Bestiole *baseBestiole, double range, double detectionProb, double fov, int age, bool isMultipleBehavior, Behavior *b) {
    return create(baseBestiole, {"yeux"}, range, detectionProb, fov, -1.0, -1.0, -1.0, isMultipleBehavior, age, b);
}


Bestiole* BestioleCreator::createFullSensor(Bestiole *baseBestiole, Behavior *b) {
    return create(baseBestiole, {"oreille", "yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createFullSensor(Behavior *b) {
    return create(nullptr, {"oreille", "yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createFullSensorMB(Bestiole *baseBestiole) {
    return create(baseBestiole, {"oreille", "yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createFullSensorMB() {
    return create(nullptr, {"oreille", "yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}


Bestiole* BestioleCreator::createFullAccesory(Bestiole *baseBestiole, Behavior *b) {
    return create(baseBestiole, {"carapace", "camouflage", "nageoire"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createFullAccesory(Behavior *b) {
    return create(nullptr, {"carapace", "camouflage", "nageoire"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createFullAccesoryMB(Bestiole *baseBestiole) {
    return create(baseBestiole, {"carapace", "camouflage", "nageoire"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createFullAccesoryMB() {
    return create(nullptr, {"carapace", "camouflage", "nageoire"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}


Bestiole* BestioleCreator::createFull(Bestiole *baseBestiole, Behavior *b) {
    return create(baseBestiole, {"carapace", "camouflage", "nageoire", "oreille", "yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createFull(Behavior *b) {
    return create(nullptr, {"carapace", "camouflage", "nageoire", "oreille", "yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, false, -1, b);
}
Bestiole* BestioleCreator::createFullMB(Bestiole *baseBestiole) {
    return create(baseBestiole, {"carapace", "camouflage", "nageoire", "oreille", "yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}
Bestiole* BestioleCreator::createFullMB() {
    return create(nullptr, {"carapace", "camouflage", "nageoire", "oreille", "yeux"}, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, true, -1, nullptr);
}