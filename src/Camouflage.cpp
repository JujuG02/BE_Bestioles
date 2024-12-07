#include "Camouflage.h"
const double Camouflage::MAX_HIDE = 1;
const double Camouflage::MIN_HIDE = 0;
const double Camouflage::DIV_COLOR = 0.5;

Camouflage::Camouflage(Bestiole &b, double hidingCoeff) {
    this->hidingCoeff = hidingCoeff;
    this->bestiole = &b;
}

Camouflage::Camouflage(Bestiole &b) {
    this->bestiole = &b;

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

void Camouflage::draw(UImg & support, double x, double y, double orientation, T* couleur) {
    // Implémentation spécifique du camouflage
    T* couleurtoset = new T[3];
    T* couleurbis = this->getCouleur();
    couleurtoset[0] = couleurbis[0]*DIV_COLOR;
    couleurtoset[1] = couleurbis[1]*DIV_COLOR;
    couleurtoset[2] = couleurbis[2]*DIV_COLOR;
    this->setCouleur(couleurtoset);
    this->bestiole->draw(support, x, y, orientation, couleurtoset);
}

bool Camouflage::collision(double deathProbability) {
    bool coll =this->bestiole->collision(deathProbability);
    if(!coll){
        orientation = turn(orientation);
    }
    return coll;
}

bool Camouflage::jeTeVois(const Bestiole &b) const {
    return this->bestiole->jeTeVois(b);
}

double Camouflage::getHidingCoeff() const {
    return hidingCoeff;
}

