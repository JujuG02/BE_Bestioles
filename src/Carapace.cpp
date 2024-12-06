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

void Carapace::draw(UImg & support, double x, double y, double orientation) {  
    // Implémentation spécifique de la carapace
    unsigned char black[] = {0, 0, 0};
    const double num_points = 6;
    const double c_size = AFF_SIZE * 1.7;
    double angle, angle2;
    // Points along the polygon
    for (int i = 0; i < num_points - 1; i++) {
        angle = i * 2 * M_PI / num_points;
        angle2 = (i + 1) * 2 * M_PI / num_points;
        support.draw_line(x + c_size * cos(angle), y - c_size * sin(angle), x + c_size * cos(angle2), y - c_size * sin(angle2), black);
    }
    support.draw_line(x + c_size * cos(angle2), y - c_size * sin(angle2), x + c_size, y, black);
    
    
    

    this->bestiole->draw(support, x, y, orientation);
}

bool Carapace::collision(double deathProbability){
   double randomValue = static_cast<double>(rand()) / RAND_MAX;
   randomValue = randomValue * this->deathCoeff;
   if (randomValue < deathProbability) {
      cout<<"Bestiole "<<this->identite<<" is dead cause of collision"<<endl;
      return true;
   } else {
      orientation += M_PI;
      if (orientation > 2 * M_PI) {
         orientation -= 2 * M_PI;
      }
      return false;
   }
}
