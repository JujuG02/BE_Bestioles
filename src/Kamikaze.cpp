#include "Kamikaze.h"
#include "Behavior.h"
#include "Bestiole.h"
#include <limits>
#include <iostream>
#include <cmath>

void Kamikaze::move(std::vector<Bestiole> &bestioleList, Bestiole &b) {

    const double VITESSE_MULTIPLIER = 10;

    // on vérifie que la liste n'est pas vide
    if (bestioleList.empty()) return;
    //on trouve la bestiole là plus proche
    double minDist = std::numeric_limits<double>::infinity();
    Bestiole* closeBestiole = &bestioleList[0];

    for(std::vector<Bestiole>::iterator it = bestioleList.begin(); it != bestioleList.end(); ++it){
    // Ignorer la bestiole elle-même
        if (&(*it) == &b) continue;

        double dist = sqrt((b.getX() - (*it).getX()) * (b.getX() - (*it).getX()) + (b.getY() - (*it).getY()) * (b.getY() - (*it).getY()));

        if(minDist> dist){
            minDist = dist;
            closeBestiole = &(*it);
        }
    }

    b.setOrientation(atan((b.getY() - closeBestiole->getY())/b.getX() - closeBestiole->getX()));
    b.setVitesse(b.getVitesse()*VITESSE_MULTIPLIER);
}
