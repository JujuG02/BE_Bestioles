#include "Peureuse.h"
#include "Bestiole.h"
#include <cmath> 

void Peureuse::move(std::vector<Bestiole> &bestioleList) {
    const int MAX_BESTIOLES = 5; 
    const double FLEE_SPEED_MULTIPLIER = 2.0; 
    int nearbyBestioles = 0;
    double avgX = 0.0;
    double avgY = 0.0;

    for (const auto &b : bestioleList) {
        if (this != &b && this->jeTeVois(b)) { // Vérifier que ce n'est pas la même bestiole et qu'elle la voit.
        //Pb car il faut appeler une bestiole qui possède l'attribut peureuse : jeTeVois est pas fait dans Peureuse.h
            nearbyBestioles++;
            avgX += b.getX();
            avgY += b.getY();
        }
    }

    if (nearbyBestioles > MAX_BESTIOLES) {
        // Calculer le barycentre
        avgX /= nearbyBestioles;
        avgY /= nearbyBestioles;

        // Calculer la direction opposée au barycentre
        double fleeX = this->getX() - avgX;
        double fleeY = this->getY() - avgY;

        // Normaliser le vecteur de fuite
        double fleeMagnitude = std::sqrt(fleeX * fleeX + fleeY * fleeY);
        fleeX = (fleeX / fleeMagnitude) * FLEE_SPEED_MULTIPLIER;
        fleeY = (fleeY / fleeMagnitude) * FLEE_SPEED_MULTIPLIER;

        // Ajuster les coordonnées cumulées pour la fuite
        this->cumulX = fleeX;
        this->cumulY = fleeY;
        
    } else {

        // Reprendre la vitesse de croisière
        this->cumulX = std::cos(this->orientation) * this->vitesse;
        this->cumulY = -std::sin(this->orientation) * this->vitesse;
    }
}
