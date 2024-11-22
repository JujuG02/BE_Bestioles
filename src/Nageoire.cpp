#include "Nageoire.h"

Nageoire::Nageoire(Bestiole &b, double speedCoeff) {
    this->speedCoeff = speedCoeff;
    this->bestiole = &b;
}

void Nageoire::draw(UImg &support, double x, double y, double orientation) {
    // Implémentation spécifique de la nageoire
}