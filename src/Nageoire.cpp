#include "Nageoire.h"

const double Nageoire::MAX_SPEED_COEFF = 10;

Nageoire::Nageoire(Bestiole &b, double speedCoeff) {
    this->speedCoeff = speedCoeff;
    this->bestiole = &b;
}

Nageoire::Nageoire(Bestiole &b) {
    //TODO: Implementer le constructeur
    this->bestiole = &b;

    std::srand(std::time(nullptr));
    this->speedCoeff = (static_cast<double>(std::rand()) / (MAX_SPEED_COEFF)); // +1 pour être entre [1;MAX_SPEED_COEFF]
}

void Nageoire::draw(UImg &support) {
    this->bestiole->draw(support);
}