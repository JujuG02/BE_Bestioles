#include "Prevoyante.h"
#include "Bestiole.h"
#include <cmath>
#include <limits>

/**
 * Comportement prévoyant : la bestiole ajuste sa trajectoire pour éviter les collisions potentielles
 * en estimant les trajectoires des bestioles environnantes.
 */
void Prevoyante::move(std::vector<Bestiole>& bestioleList, Bestiole& b) {
    if (bestioleList.empty()) return;

    double newOrientation = b.getOrientation();
    double minDist = std::numeric_limits<double>::max(); // Utilisation de la distance maximale possible

    for (auto& other : bestioleList) {
        if (&other == &b) continue; // On évite la comparaison avec elle-même

        // Estimation de la future position de l'autre bestiole
        double otherFutureX = other.getX() + std::cos(other.getOrientation()) * other.getVitesse();
        double otherFutureY = other.getY() - std::sin(other.getOrientation()) * other.getVitesse();

        // Estimation de la future position de la bestiole courante
        double bFutureX = b.getX() + std::cos(newOrientation) * b.getVitesse();
        double bFutureY = b.getY() - std::sin(newOrientation) * b.getVitesse();

        // Calcul de la distance entre les positions futures
        double dist = std::sqrt(std::pow(bFutureX - otherFutureX, 2) + std::pow(bFutureY - otherFutureY, 2));

        // Ajustement de l'orientation pour éviter les collisions
        if (dist < minDist) {
            minDist = dist;
            newOrientation = std::atan2(b.getY() - otherFutureY, b.getX() - otherFutureX); 
        }
    }

    // Mettre à jour l'orientation de la bestiole
    b.setOrientation(newOrientation);
    b.setCumulX(std::cos(newOrientation) * b.getVitesse());
    b.setCumulY(-std::sin(newOrientation) * b.getVitesse());
}
