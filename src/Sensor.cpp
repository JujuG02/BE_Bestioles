#include "Sensor.h"

Sensor::Sensor(Bestiole &b, double range, double directionProb, double fov){
    this->range = range;
    this->directionProb = directionProb;
    if(fov==0.0){
        fov = 2*M_PI;
    }
    this->fov = fov;
    this->bestiole = &b;
}

void Sensor::draw(UImg &support, double x, double y, double orientation) {
    // Implémentation spécifique du capteur
}