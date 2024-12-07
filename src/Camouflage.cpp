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
    // Le camouflage est représenté par une couleur plus claire, et un disque transparent entourant la bestiole
    T* couleurtoset = new T[3];
    T* couleurbis = this->getCouleur(); // On récupère la couleur de la bestiole
    couleurtoset[0] = couleurbis[0]*DIV_COLOR;  // Puis on la rend plus claire
    couleurtoset[1] = couleurbis[1]*DIV_COLOR;
    couleurtoset[2] = couleurbis[2]*DIV_COLOR;
    this->setCouleur(couleurtoset);             
    support.draw_circle(x, y, 1.6 * AFF_SIZE, couleurtoset, 0.2 ); // On dessine un cercle de la même couleur autour
    
    // Le reste de l'affichage est géré par la bestiole décorée antérieure.
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

