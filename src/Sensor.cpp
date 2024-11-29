#include "Sensor.h"

const double Sensor::MAX_FOV = M_PI;
const double Sensor::MIN_FOV = 0.1;
const double Sensor::MAX_RANGE = 100;
const double Sensor::MIN_RANGE = 10;
const double Sensor::MAX_DETEC_PROB = 1;
const double Sensor::MIN_DETEC_PROB = 0.5;

Sensor::Sensor(Bestiole &b, double range, double directionProb, double fov){
    this->range = range;
    this->directionProb = directionProb;
    if(fov==-1.0){
        fov = 2*M_PI;
    }
    this->fov = fov;
    this->bestiole = &b;
}

Sensor::Sensor(Bestiole &b, bool isYeux){
    if(isYeux){ 
        this->fov = MIN_FOV + static_cast<double>(rand()) / RAND_MAX * (MAX_FOV - MIN_FOV);
    }
    else{
        this->fov = 2*M_PI;
    }
    this->range = MIN_RANGE + static_cast<double>(rand()) / RAND_MAX * (MAX_RANGE - MIN_RANGE);
    this->directionProb = MIN_DETEC_PROB + static_cast<double>(rand()) / RAND_MAX * (MAX_DETEC_PROB - MIN_DETEC_PROB);
    this->bestiole = &b;
}

Sensor::Sensor(Sensor const &s){
    this->range = s.range;
    this->directionProb = s.directionProb;
    this->fov = s.fov;
    this->bestiole = s.bestiole->clone();
}

Sensor& Sensor::operator=(Sensor const &s){
    if(this != &s){
        this->range = s.range;
        this->directionProb = s.directionProb;
        this->fov = s.fov;
        this->bestiole = s.bestiole;
    }
    return *this;
}

Sensor* Sensor::clone() const {
    return new Sensor(*this);
}

void Sensor::draw(UImg &support, double x, double y, double orientation) {
    // Implémentation spécifique du capteur
}

bool Sensor::jeTeVois(const Bestiole &b) const {
    int bx = b.getX();
    int by = b.getY();
    double dist = std::sqrt( (this->bestiole->getX() - bx)*(this->bestiole->getX() - bx) + (this->bestiole->getY() - by)*(this->bestiole->getY() - by) );
    double angle = std::atan2(by - this->bestiole->getY(), bx - this->bestiole->getX());

    return (dist<=this->range
        && std::abs(angle - this->bestiole->getOrientation()) <= this->fov/2);
}