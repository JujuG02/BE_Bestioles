#include "Nageoire.h"

const double Nageoire::MAX_SPEED_COEFF = 10;

Nageoire::Nageoire(Bestiole &b, double speedCoeff) {
    this->speedCoeff = speedCoeff;
    this->bestiole = &b;
    this->vitesse = this->vitesse*speedCoeff;
}

Nageoire::Nageoire(Bestiole &b) {
    this->bestiole = &b;

    std::srand(std::time(nullptr));
    this->speedCoeff = 1 + (static_cast<double>(std::rand()) / (RAND_MAX * (MAX_SPEED_COEFF - 1)));
    this->vitesse = this->vitesse*speedCoeff;
}

Nageoire::Nageoire(Nageoire const &n) {
    this->speedCoeff = n.speedCoeff;
    this->bestiole = n.bestiole->clone();
}

Nageoire& Nageoire::operator=(Nageoire const &n) {
    if(this != &n){
        this->speedCoeff = n.speedCoeff;
        this->bestiole = n.bestiole->clone();
    }
    return *this;
}

Nageoire* Nageoire::clone() const {
    return new Nageoire(*this);
}

Nageoire::~Nageoire() {
    delete this->bestiole;
}

void Nageoire::draw(UImg &support) {
    this->bestiole->draw(support);
}