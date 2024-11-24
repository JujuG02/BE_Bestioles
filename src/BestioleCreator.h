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
                        double fov = -1.0, 
                        double range = -1.0, 
                        double detectionProb = -1.0, 
                        double speedCoeff = -1.0,
                        double hidingCoeff = -1.0,
                        double deathCoeff = -1.0,
                        bool isMultipleBehavior = false,
                        int age = -1,
                        Behavior *b = nullptr) const;
        
        Bestiole* createNageoire(Bestiole *baseBestiole = nullptr, Behavior *b);
        Bestiole* createNageoireMB(Bestiole *baseBestiole = nullptr);
        Bestiole* createNageoirCustom(Bestiole *baseBestiole = nullptr,
                                         double speedCoeff,
                                         int age,
                                         bool isMultipleBehavior,
                                         Behavior *b);

        Bestiole* createCarapace(Bestiole *baseBestiole = nullptr, Behavior *b);
        Bestiole* createCarapaceMB(Bestiole *baseBestiole = nullptr);
        Bestiole* createCarapaceCustom(Bestiole *baseBestiole = nullptr,
                                         double deathCoeff,
                                         double speedCoeff,
                                         int age,
                                         bool isMultipleBehavior,
                                         Behavior *b);

        Bestiole* createCamouflage(Bestiole *baseBestiole = nullptr, Behavior *b);
        Bestiole* createCamouflageMB(Bestiole *baseBestiole = nullptr);
        Bestiole* createCamouflageCustom(Bestiole *baseBestiole = nullptr,
                                         double hidingCoeff,
                                         int age,
                                         bool isMultipleBehavior,
                                         Behavior *b);

        Bestiole* createOreille(Bestiole *baseBestiole = nullptr, Behavior *b);
        Bestiole* createOreilleMB(Bestiole *baseBestiole = nullptr);
        Bestiole* createOreilleCustom(Bestiole *baseBestiole = nullptr,
                                         double range,
                                         double detectionProb,
                                         int age,
                                         bool isMultipleBehavior,
                                         Behavior *b);

        Bestiole* createYeux(Bestiole *baseBestiole = nullptr, Behavior *b);
        Bestiole* createYeuxMB(Bestiole *baseBestiole = nullptr);
        Bestiole* createYeuxCustom(Bestiole *baseBestiole = nullptr,
                                         double range,
                                         double detectionProb,
                                         double fov,
                                         int age,
                                         bool isMultipleBehavior,
                                         Behavior *b);

        Bestiole* createFullSensor(Bestiole *baseBestiole = nullptr, Behavior *b);
        Bestiole* createFullSensorMB(Bestiole *baseBestiole = nullptr);

        Bestiole* createFullAccesory(Bestiole *baseBestiole = nullptr, Behavior *b);
        Bestiole* createFullAccesoryMB(Bestiole *baseBestiole = nullptr);

        Bestiole* createFull(Bestiole *baseBestiole = nullptr, Behavior *b);
        Bestiole* createFullMB(Bestiole *baseBestiole = nullptr);    

};





#endif