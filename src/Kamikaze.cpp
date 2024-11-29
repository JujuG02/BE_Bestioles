#include "Kamikaze.h"
#include "Behavior.h"
#include "Bestiole.h"
#include <limits>
#include <iostream>
#include <cmath>

void Kamikaze::move(std::vector<Bestiole> &bestioleList, Bestiole &b) {
    // Vérifier que la liste n'est pas vide
    if (bestioleList.empty()) return;
    //on trouve la bestiole là plus proche
    double minDist = std::numeric_limits<double>::infinity();
    Bestiole* closeBestiole = &bestioleList[0];

    for(std::vector<Bestiole>::iterator it = bestioleList.begin(); it != bestioleList.end(); ++it){
    // Ignorer la bestiole elle-même
        if (&(*it) == &b) continue;

        double dist = sqrt((b.x-(*it).x)*(b.x-(*it).x) + (b.y-(*it).y)*(b.y-(*it).y));

        if(minDist> dist){
            minDist = dist;
            closeBestiole = &(*it);
        }
    }

    // Si une bestiole proche a été trouvée, bouger vers elle
    if (closeBestiole != nullptr) {
        b.bouge(closeBestiole->x, closeBestiole->y);
    }



}
