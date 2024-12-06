#include "Kamikaze.h"
#include "Behavior.h"
#include "Bestiole.h"
#include <limits>
#include <iostream>
#include <cmath>

void Kamikaze::move(std::vector<Bestiole> &bestioleList, Bestiole &b) {

    const double VITESSE_MULTIPLIER = 10;
    const double DISTANCE_CRITIQUE = 50.0;

    // on vérifie que la liste n'est pas vide
    if (bestioleList.empty()) return;
    //on trouve la bestiole là plus proche
    double minDist = std::numeric_limits<double>::infinity();
    Bestiole* closeBestiole = &bestioleList[0];

    for(std::vector<Bestiole>::iterator it = bestioleList.begin(); it != bestioleList.end(); ++it){
    // Ignorer la bestiole elle-même
        if (&(*it) == &b) continue;

    // Calculer la distance
        double dx = b.getX() - it->getX();
        double dy = b.getY() - it->getY();
        double dist = sqrt(dx * dx + dy * dy);

        if(minDist> dist){//on choisi le plus proche voisin
            minDist = dist;
            closeBestiole = &(*it);
        }
    }

    double dx = closeBestiole->getX() - b.getX();
    double dy = closeBestiole->getY() - b.getY();
    double orientation = atan2(-dy, dx);

    std::cout<< "Le bestiole "<< b.getIdentite()<< "a pour orientation"<<b.getOrientation() <<','<<endl;
    b.setOrientation(orientation);
    std::cout<<b.getOrientation()<<endl;
    b.setVitesse(VITESSE_MULTIPLIER*closeBestiole->getVitesse());
    }
