#include "Peureuse.h"
#include "Bestiole.h"
#include <cmath>

/*
 * Comportement peureux : la bestiole ajuste son orientation et sa vitesse pour fuir 
 * dans une direction optimale puis revient à sa vitesse normale après un délai de 1 seconde.
 */

void Peureuse::move(std::vector<Bestiole>& bestioleList, Bestiole& b) {
    const int MAX_BESTIOLES = 5;
    const double FLEE_SPEED_MULTIPLIER = 2.0; 
    static const double ORIGINAL_SPEED = b.getVitesse(); // Sauvegarde de la vitesse originale
    int nearbyBestioles = 0;
    double avgX = 0.0;
    double avgY = 0.0;

    // Compter le nombre de bestioles à proximité et calculer la moyenne de leurs positions
    for (const auto& bestiole : bestioleList) {
        nearbyBestioles++;
        avgX += bestiole.getX();
        avgY += bestiole.getY();
    }

    // Si le nombre de bestioles à proximité MAX_BESTIOLES, la bestiole fuit
    if (nearbyBestioles > MAX_BESTIOLES) {
        currentCooldown = cooldownTime; 

        avgX /= nearbyBestioles;
        avgY /= nearbyBestioles;

        // Calculer la direction de fuite de la bestiole (opposée à la moyenne des positions)
        double fleeX = b.getX() - avgX;
        double fleeY = b.getY() - avgY;

        // Calculer l'orientation de fuite et la nouvelle vitesse
        double fleeOrientation = std::atan2(-fleeY, fleeX);
        double fleeVitesse = b.getVitesse() * FLEE_SPEED_MULTIPLIER;

        // Mettre à jour l'orientation et la vitesse de la bestiole
        b.setOrientation(fleeOrientation);
        b.setVitesse(fleeVitesse);

        // Mettre à jour les composantes du mouvement
        b.setCumulX(std::cos(b.getOrientation()) * b.getVitesse());
        b.setCumulY(-std::sin(b.getOrientation()) * b.getVitesse());

    // Gestion du cooldown (la bestiole garde sa direction et vitesse de fuite)
    } else if (currentCooldown > 0) {
        currentCooldown--;

        b.setCumulX(std::cos(b.getOrientation()) * b.getVitesse());
        b.setCumulY(-std::sin(b.getOrientation()) * b.getVitesse());

    // Retour à la vitesse normale après le cooldown
    } else if (b.getVitesse() > ORIGINAL_SPEED) {  // Permet de s'assurer que la vitesse revient à la normale une seule fois
        b.setVitesse(ORIGINAL_SPEED);
        b.setCumulX(std::cos(b.getOrientation()) * b.getVitesse());
        b.setCumulY(-std::sin(b.getOrientation()) * b.getVitesse());
    }
}
