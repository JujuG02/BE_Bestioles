#include "Peureuse.h"
#include "Bestiole.h"
#include <cmath>

void Peureuse::move(std::vector<Bestiole>& bestioleList, Bestiole& b) {
    const int MAX_BESTIOLES = 5;
    const double FLEE_SPEED_MULTIPLIER = 2.0; 
    int nearbyBestioles = 0;
    double avgX = 0.0;
    double avgY = 0.0;

    // Parcourt chaque bestiole de la liste pour accumuler leurs coordonnées
    for (const auto& bestiole : bestioleList) {
        nearbyBestioles++;
        avgX += bestiole.getX();
        avgY += bestiole.getY();
    }

    // Si le nombre de bestioles environnantes dépasse MAX_BESTIOLES, la bestiole fuit
    if (nearbyBestioles > MAX_BESTIOLES) {
        // Calculer le barycentre des bestioles environnantes 
        avgX /= nearbyBestioles;
        avgY /= nearbyBestioles;

        // Calculer la direction opposée au barycentre
        double fleeX = b.getX() - avgX;
        double fleeY = b.getY() - avgY;

        // Normaliser le vecteur de fuite
        double fleeMagnitude = std::sqrt(fleeX * fleeX + fleeY * fleeY);
        fleeX = (fleeX / fleeMagnitude) * FLEE_SPEED_MULTIPLIER;
        fleeY = (fleeY / fleeMagnitude) * FLEE_SPEED_MULTIPLIER;

        // Ajuster les coordonnées cumulées pour la fuite
        b.setCumulX(fleeX);
        b.setCumulY(fleeY);
        
    } else {
        // Reprendre la vitesse classique
        b.setCumulX(std::cos(b.getOrientation()) * b.getVitesse());
        b.setCumulY(-std::sin(b.getOrientation()) * b.getVitesse());
    }
}
