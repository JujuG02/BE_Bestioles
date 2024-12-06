#ifndef _BESTIOLECREATOR_H_
#define _BESTIOLECREATOR_H_

#include "Creator.h"
#include "Decorator.h"
#include "Behavior.h"

class BestioleCreator : public Creator {
    public :
        virtual ~BestioleCreator() = default;
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
        
        Bestiole* createBasic(Behavior *b);
        
        Bestiole* createNageoire(Bestiole *baseBestiole, Behavior *b);
        Bestiole* createNageoire(Behavior *b);
        Bestiole* createNageoireMB(Bestiole *baseBestiole);
        Bestiole* createNageoireMB();
        Bestiole* createNageoirCustom(Bestiole *baseBestiole,
                                         double speedCoeff,
                                         int age,
                                         bool isMultipleBehavior,
                                         Behavior *b);

        Bestiole* createCarapace(Bestiole *baseBestiole, Behavior *b);
        Bestiole* createCarapace(Behavior *b);
        Bestiole* createCarapaceMB(Bestiole *baseBestiole);
        Bestiole* createCarapaceMB();
        Bestiole* createCarapaceCustom(Bestiole *baseBestiole,
                                         double deathCoeff,
                                         double speedCoeff,
                                         int age,
                                         bool isMultipleBehavior,
                                         Behavior *b);

        Bestiole* createCamouflage(Bestiole *baseBestiole, Behavior *b);
        Bestiole* createCamouflage(Behavior *b);
        Bestiole* createCamouflageMB(Bestiole *baseBestiole);
        Bestiole* createCamouflageMB();
        Bestiole* createCamouflageCustom(Bestiole *baseBestiole,
                                         double hidingCoeff,
                                         int age,
                                         bool isMultipleBehavior,
                                         Behavior *b);

        Bestiole* createOreille(Bestiole *baseBestiole, Behavior *b);
        Bestiole* createOreille(Behavior *b);
        Bestiole* createOreilleMB(Bestiole *baseBestiole);
        Bestiole* createOreilleMB();
        Bestiole* createOreilleCustom(Bestiole *baseBestiole,
                                         double range,
                                         double detectionProb,
                                         int age,
                                         bool isMultipleBehavior,
                                         Behavior *b);

        Bestiole* createYeux(Bestiole *baseBestiole, Behavior *b);
        Bestiole* createYeux(Behavior *b);
        Bestiole* createYeuxMB(Bestiole *baseBestiole);
        Bestiole* createYeuxMB();
        Bestiole* createYeuxCustom(Bestiole *baseBestiole,
                                         double range,
                                         double detectionProb,
                                         double fov,
                                         int age,
                                         bool isMultipleBehavior,
                                         Behavior *b);

        Bestiole* createFullSensor(Bestiole *baseBestiole, Behavior *b);
        Bestiole* createFullSensor(Behavior *b);
        Bestiole* createFullSensorMB(Bestiole *baseBestiole);
        Bestiole* createFullSensorMB();

        Bestiole* createFullAccesory(Bestiole *baseBestiole, Behavior *b);
        Bestiole* createFullAccesory(Behavior *b);
        Bestiole* createFullAccesoryMB(Bestiole *baseBestiole);
        Bestiole* createFullAccesoryMB();

        Bestiole* createFull(Bestiole *baseBestiole, Behavior *b);
        Bestiole* createFull(Behavior *b);
        Bestiole* createFullMB(Bestiole *baseBestiole);    
        Bestiole* createFullMB();

};





#endif