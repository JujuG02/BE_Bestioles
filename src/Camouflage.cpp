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

Camouflage::Camouflage(Camouflage const &c) {
    this->hidingCoeff = c.hidingCoeff;
    this->bestiole = c.bestiole->clone();
}

Camouflage& Camouflage::operator=(Camouflage const &c) {
    if(this != &c){
        this->hidingCoeff = c.hidingCoeff;
        this->bestiole = c.bestiole->clone();
    }
    return *this;
}

Camouflage* Camouflage::clone() const {
    return new Camouflage(*this);
}

Camouflage::~Camouflage() {
    delete this->bestiole;
}

void Camouflage::draw(UImg &support) {
    // Implémentation spécifique du camouflage
    this->bestiole->draw(support);
}

double Camouflage::getHidingCoeff() const {
    return hidingCoeff;
}