#include "Camouflage.h"
const double Camouflage::MAX_HIDE = 1;
const double Camouflage::MIN_HIDE = 0;

Camouflage::Camouflage(Bestiole &b, double hidingCoeff) {
    this->hidingCoeff = hidingCoeff;
    this->bestiole = &b;
}

Camouflage::Camouflage(Bestiole &b) {
    this->bestiole = &b;

    std::srand(std::time(nullptr));
    this->hidingCoeff = MIN_HIDE + static_cast<double>(std::rand()) / RAND_MAX * (MAX_HIDE - MIN_HIDE);
}

void Camouflage::draw(UImg &support) {
    // Implémentation spécifique du camouflage
    this->bestiole->draw(support);
}

double Camouflage::getHidingCoeff() const {
    return hidingCoeff;
}