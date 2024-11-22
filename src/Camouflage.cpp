#include "Camouflage.h"

Camouflage::Camouflage(Bestiole &b, double hidingCoeff) {
    this->hidingCoeff = hidingCoeff;
    this->bestiole = &b;
}

void Camouflage::draw(UImg &support, double x, double y, double orientation) {
    // Implémentation spécifique du camouflage
}