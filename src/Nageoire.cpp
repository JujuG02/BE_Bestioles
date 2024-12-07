#include "Nageoire.h"

const double Nageoire::MAX_SPEED_COEFF = 10;

Nageoire::Nageoire(Bestiole &b, double speedCoeff) {
    this->speedCoeff = speedCoeff;
    this->bestiole = &b;
    this->vitesse = this->vitesse*speedCoeff;
}

Nageoire::Nageoire(Bestiole &b) {
    this->bestiole = &b;

    this->speedCoeff = 1 + (static_cast<double>(std::rand()) / (RAND_MAX * (MAX_SPEED_COEFF - 1)));
    this->setVitesse(this->vitesse*speedCoeff);
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

void Nageoire::draw(UImg & support, double x, double y, double orientation, T* couleur) {
    double xt = x + cos( orientation )*AFF_SIZE/2.1;
    double yt = y - sin( orientation )*AFF_SIZE/2.1;

    // Implémentation spécifique de la nageoire
    // Représentée par un triangle au niveau du centre de la bestiole
    double finWidth =  1.5; // Largeur des nageoires
    double finHeight = 2.5; // Hauteur (longueur) des nageoires

    // Détermination des ponits du triangle
    double x2 = x + cos(orientation - M_PI / 2.) * AFF_SIZE * finWidth;
    double y2 = y - sin(orientation - M_PI / 2.) * AFF_SIZE * finWidth;
    double x3 = x + cos(orientation + M_PI / 2.) * AFF_SIZE * finWidth;
    double y3 = y - sin(orientation + M_PI / 2.) * AFF_SIZE * finWidth;

    support.draw_triangle(xt + cos( orientation ) * finHeight * AFF_SIZE/2.1,
                          yt - sin( orientation ) *  finHeight * AFF_SIZE/2.1,
                          x2, y2, x3, y3, couleur);
    
    // Le reste de l'affichage est géré par la bestiole décorée antérieure.
    this->bestiole->draw(support, x, y, orientation, couleur);
}

bool Nageoire::collision(double deathProbability) {
    bool coll = this->bestiole->collision(deathProbability);
    if(!coll){
        orientation = turn(orientation);
    }
    return coll;
}

bool Nageoire::jeTeVois(const Bestiole &b) const {
    return this->bestiole->jeTeVois(b);
}

double Nageoire::getHidingCoeff() const {
    return this->bestiole->getHidingCoeff();
}