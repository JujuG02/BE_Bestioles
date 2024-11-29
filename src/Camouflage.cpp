#include "Camouflage.h"
const double Camouflage::MAX_HIDE = 0;
const double Camouflage::MIN_HIDE = 1;

Camouflage::Camouflage(Bestiole &b, double hidingCoeff) {
    this->hidingCoeff = hidingCoeff;
    this->bestiole = &b;
}

Camouflage::Camouflage(Bestiole &b) {
    //TODO: Implementer le constructeur
    this->bestiole = &b;

    std::srand(std::time(nullptr));
    this->hidingCoeff = static_cast<double>(std::rand()) / (MAX_HIDE);
}

void Camouflage::draw(UImg &support) {
    // Implémentation spécifique du camouflage
    this->bestiole->draw(support);
}

double Camouflage::getHidingCoeff() const {
    return hidingCoeff;
}