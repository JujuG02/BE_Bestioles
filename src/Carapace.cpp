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

void Carapace::draw(UImg &support) {
    // Implémentation spécifique de la carapace
   /*const double width = 20.0;
    const double height = 10.0;
    const double angle = orientation * M_PI / 180.0;

    double x1 = x + width * cos(angle) - height * sin(angle);
    double y1 = y + width * sin(angle) + height * cos(angle);
    double x2 = x - width * cos(angle) - height * sin(angle);
    double y2 = y - width * sin(angle) + height * cos(angle);
    double x3 = x - width * cos(angle) + height * sin(angle);
    double y3 = y - width * sin(angle) - height * cos(angle);
    double x4 = x + width * cos(angle) + height * sin(angle);
    double y4 = y + width * sin(angle) - height * cos(angle);

    unsigned char black[] = {0, 0, 0};
    support.draw_line(x1, y1, x2, y2, black);
    support.draw_line(x2, y2, x3, y3, black);
    support.draw_line(x3, y3, x4, y4, black);
    support.draw_line(x4, y4, x1, y1, black);*/

    this->bestiole->draw(support);
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
