#include "Peureuse.h"
#include "Bestiole.h"
#include <cmath>
#include <vector>

/*
 * Comportement peureux : la bestiole ajuste son orientation et sa vitesse pour fuir 
 * dans une direction opposée dès qu'elle voit une autre bestiole.
 */

void Peureuse::move(std::vector<Bestiole>& bestioleList, Bestiole& b) {
    const double FLEE_SPEED_MULTIPLIER = 2.0;
    static const double ORIGINAL_SPEED = b.getVitesse();

    // Mise de couleur standard pour les peureuses (vert)
    if (b.getCouleur()[0] != 0 || b.getCouleur()[1] != 255 || b.getCouleur()[2] != 0) {
        T* couleur = new T[3];
        couleur[0] = 0;
        couleur[1] = 255;
        couleur[2] = 0;

        b.setCouleur(couleur);
    }

    for (const auto& other : bestioleList) {
        if (&other == &b) continue; // On évite la comparaison avec elle-même

        // Calcul de la direction opposée
        double fleeOrientation = std::atan2(b.getY() - other.getY(), b.getX() - other.getX());

        // Ajustement de l'orientation et de la vitesse pour fuir
        b.setOrientation(fleeOrientation);
        b.setVitesse(b.getVitesse() * FLEE_SPEED_MULTIPLIER);
        b.setCumulX(std::cos(fleeOrientation) * b.getVitesse());
        b.setCumulY(-std::sin(fleeOrientation) * b.getVitesse());

        return;
    }

    // Si aucune bestiole n'est détectée, la vitesse revient à la normale
    if (b.getVitesse() > ORIGINAL_SPEED) {  // Permet de s'assurer que la vitesse revient à la normale une seule fois
        b.setVitesse(ORIGINAL_SPEED);
        b.setCumulX(std::cos(b.getOrientation()) * b.getVitesse());
        b.setCumulY(-std::sin(b.getOrientation()) * b.getVitesse());
    }
}