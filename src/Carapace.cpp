#include "Carapace.h"
#include "UImg.h"
#include <cmath>

const double Carapace::MIN_DEATH_COEFF = 0.1;
const double Carapace::MIN_SPEED_COEFF = 0.1;

Carapace::Carapace(Bestiole &b, double deathCoeff, double speedCoeff) {
    this->deathCoeff = deathCoeff;
    this->speedCoeff = speedCoeff;
    this->bestiole = &b;
}

Carapace::Carapace(Bestiole &b) {
    this->bestiole = &b;

    //génération des valeurs aléatoires
    double randDeath = MIN_DEATH_COEFF + static_cast<double>(std::rand()) / RAND_MAX * (1 - MIN_DEATH_COEFF);
    this->deathCoeff = randDeath;
    double randSpeed = MIN_SPEED_COEFF + static_cast<double>(std::rand()) / RAND_MAX * (1 - MIN_SPEED_COEFF);
    this->speedCoeff = randSpeed;
    this->vitesse = this->vitesse*speedCoeff;
}

Carapace::Carapace(Carapace const &c) {
    this->deathCoeff = c.deathCoeff;
    this->speedCoeff = c.speedCoeff;
    this->bestiole = c.bestiole->clone();
}

Carapace& Carapace::operator=(Carapace const &c) {
    if(this != &c){
        this->deathCoeff = c.deathCoeff;
        this->speedCoeff = c.speedCoeff;
        this->bestiole = c.bestiole->clone();
    }
    return *this;
}

Carapace* Carapace::clone() const {
    return new Carapace(*this);
}

Carapace::~Carapace() {
    delete this->bestiole;
}

void Carapace::draw(UImg & support, double x, double y, double orientation, T* couleur) {  
    // Implémentation spécifique de la carapace
    unsigned char black[] = {0, 0, 0};
    const double num_points = 6; // Hexagone : 6 points
    const double c_size = AFF_SIZE * 1.7; // Taille de la carapace
    double angle, angle2;
    // Relier les points de l'hexagone
    for (int i = 0; i < num_points - 1; i++) {
        angle = i * 2 * M_PI / num_points;
        angle2 = (i + 1) * 2 * M_PI / num_points;
        support.draw_line(x + c_size * cos(angle), y - c_size * sin(angle), x + c_size * cos(angle2), y - c_size * sin(angle2), black);
    }
    // Dernière ligne de l'hexagone
    support.draw_line(x + c_size * cos(angle2), y - c_size * sin(angle2), x + c_size, y, black);

    // Le reste de l'affichage est géré par la bestiole décorée antérieure.
    this->bestiole->draw(support, x, y, orientation, couleur);
}

bool Carapace::collision(double deathProbability){
   return this->bestiole->collision(deathProbability*this->deathCoeff);
}

bool Carapace::jeTeVois(const Bestiole &b) const {
   return this->bestiole->jeTeVois(b);
}

double Carapace::getHidingCoeff() const {
    return this->bestiole->getHidingCoeff();
}
