#include "Peureuse.h"
#include "Bestiole.h"
#include <cmath>

/*
 * Comportement peureux : la bestiole ajuste son orientation et sa vitesse pour fuir 
 * dans une direction optimale puis revient à se vitesse normale après un délai de 1 seconde
 */

void Peureuse::move(std::vector<Bestiole>& bestioleList, Bestiole& b) {
    const int MAX_BESTIOLES = 5;
    const double FLEE_SPEED_MULTIPLIER = 2.0; 
    int nearbyBestioles = 0;
    double avgX = 0.0;
    double avgY = 0.0;

    for (const auto& bestiole : bestioleList) {
        nearbyBestioles++;
        avgX += bestiole.getX();
        avgY += bestiole.getY();
    }

    if (nearbyBestioles > MAX_BESTIOLES) {
        currentCooldown = cooldownTime;

        avgX /= nearbyBestioles;
        avgY /= nearbyBestioles;

        double fleeX = b.getX() - avgX;
        double fleeY = b.getY() - avgY;

        double fleeOrientation = std::atan2(-fleeY, fleeX);
        double fleeVitesse = b.getVitesse() * FLEE_SPEED_MULTIPLIER;

        b.setOrientation(fleeOrientation);
        b.setVitesse(fleeVitesse);

        b.setCumulX(std::cos(b.getOrientation()) * b.getVitesse());
        b.setCumulY(-std::sin(b.getOrientation()) * b.getVitesse());

    } else if (currentCooldown > 0) {
        currentCooldown--;

        b.setCumulX(std::cos(b.getOrientation()) * b.getVitesse());
        b.setCumulY(-std::sin(b.getOrientation()) * b.getVitesse());

    } else {
        b.setVitesse(b.getVitesse() / FLEE_SPEED_MULTIPLIER);
        b.setCumulX(std::cos(b.getOrientation()) * b.getVitesse());
        b.setCumulY(-std::sin(b.getOrientation()) * b.getVitesse());
    }
}
