#include "Nageoire.h"

Nageoire::Nageoire(Bestiole &b, double speedCoeff) {
    this->speedCoeff = speedCoeff;
    this->bestiole = &b;
}

Nageoire::Nageoire(Bestiole &b) {
    //TODO: Implementer le constructeur
}

void Nageoire::draw(UImg &support, double x, double y, double orientation) {
    // Implémentation spécifique de la nageoire
}