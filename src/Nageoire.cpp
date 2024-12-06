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

void Nageoire::draw(UImg & support, double x, double y, double orientation) {
    // Affichage de la bestiole
    double xt = x + cos( orientation )*AFF_SIZE/2.1;
    double yt = y - sin( orientation )*AFF_SIZE/2.1;
    //support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
    //support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

    // Implémentation spécifique de la nageoire
    double finWidth =  1.5;
    double finHeight = 2.5;
    double x2 = x + cos(orientation - M_PI / 2.) * AFF_SIZE * finWidth;
    double y2 = y - sin(orientation - M_PI / 2.) * AFF_SIZE * finWidth;
    double x3 = x + cos(orientation + M_PI / 2.) * AFF_SIZE * finWidth;
    double y3 = y - sin(orientation + M_PI / 2.) * AFF_SIZE * finWidth;

    support.draw_triangle(xt + cos( orientation ) * finHeight * AFF_SIZE/2.1,
                          yt - sin( orientation ) *  finHeight * AFF_SIZE/2.1,
                          x2, y2, x3, y3, couleur);
    
    
    this->bestiole->draw(support, x, y, orientation);
}

bool Nageoire::collision(double deathProbability) {
    return this->bestiole->collision(deathProbability);
}

bool Nageoire::jeTeVois(const Bestiole &b) const {
    return this->bestiole->jeTeVois(b);
}