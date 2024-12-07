#include "Sensor.h"
#include "Camouflage.h"
#include "UImg.h"



const double Sensor::MAX_FOV = M_PI;
const double Sensor::MIN_FOV = 0.1;
const double Sensor::MAX_RANGE = 100;
const double Sensor::MIN_RANGE = 10;
const double Sensor::MAX_DETEC_PROB = 1;
const double Sensor::MIN_DETEC_PROB = 0.5;

Sensor::Sensor(Bestiole &b, double range, double detectionProb, double fov){
    this->range = range;
    this->detectionProb = detectionProb;
    if(fov==-1.0){
        // Si le champ vaut -1 on considère que ce sont des oreilles
        fov = 2*M_PI;
    }
    this->fov = fov;
    this->bestiole = &b;
}

Sensor::Sensor(Bestiole &b, bool isYeux){
    if(isYeux){ 
        // Champ de vision aléatoire entre MIN_FOV et MAX_FOV
        this->fov = MIN_FOV + static_cast<double>(rand()) / RAND_MAX * (MAX_FOV - MIN_FOV);
    }
    else{
        // Champ de détéction à 360 degrés
        this->fov = 2*M_PI;
    }
    this->range = MIN_RANGE + static_cast<double>(rand()) / RAND_MAX * (MAX_RANGE - MIN_RANGE);
    this->detectionProb = MIN_DETEC_PROB + static_cast<double>(rand()) / RAND_MAX * (MAX_DETEC_PROB - MIN_DETEC_PROB);
    this->bestiole = &b;
}

Sensor::Sensor(Sensor const &s){
    this->range = s.range;
    this->detectionProb = s.detectionProb;
    this->fov = s.fov;
    this->bestiole = s.bestiole->clone();
}

Sensor& Sensor::operator=(Sensor const &s){
    if(this != &s){
        this->range = s.range;
        this->detectionProb = s.detectionProb;
        this->fov = s.fov;
        this->bestiole = s.bestiole->clone();
    }
    return *this;
}

Sensor* Sensor::clone() const {
    return new Sensor(*this);
}
Sensor::~Sensor(){
    delete this->bestiole;
}

void Sensor::draw(UImg & support, double x, double y, double orientation, T* couleur) {
    // Implémentation spécifique du sensor
    // Représenté par une portion de disque transparente:
    // - Grise si ce sont des yeux
    // - Orange si ce sont des oreilles
    double startAngle = orientation - fov / 2;
    double endAngle = orientation + fov / 2;
    unsigned char black[] = {0, 0, 0};
    unsigned char orange[] = {255, 165, 0};

    // Nombre de points de l'arc
    const int num_points = 20;
    CImg<double> points(num_points + 1, 2);

    // Centre de la portion du disque
    points(0, 0) = static_cast<int>(x);;
    points(0, 1) = static_cast<int>(y);
    
    // Points de la portion du disque
    for (int i = 0; i < num_points; i++) {
        double angle = startAngle + i * (endAngle - startAngle) / (num_points - 1);
        points(i+1, 0) = static_cast<int>(x + range * cos(angle));
        points(i+1, 1) = static_cast<int>(y - range * sin(angle));
    }
    
    // Draw the filled arc as a polygon
    if (fov < 1.5 * M_PI) {
        // Yeux
        support.draw_polygon(points, black, 0.2);
    }
    else {
        // Oreilles
        support.draw_polygon(points, orange, 0.2);
    }
    
    // Le reste de l'affichage est géré par la bestiole décorée antérieure.
    this->bestiole->draw(support, x, y, orientation, couleur);
}

bool Sensor::collision(double deathProbability){
    return this->bestiole->collision(deathProbability);
}

bool Sensor::jeTeVois(const Bestiole &b) const{
    int bx = b.getX();
    int by = b.getY();
    double dist = std::sqrt( (this->x - bx)*(this->x - bx) + (this->y - by)*(this->y - by) );
    double angle = std::atan2(bx - this->x, by - this->y);

    bool detecable = dist<=this->range
        && std::abs(angle - this->getOrientation()) <= this->fov/2;
    
    double randomValue = static_cast<double>(rand()) / RAND_MAX;
    double detectionProba = this->detectionProb * b.getHidingCoeff();

    return detecable && randomValue <= detectionProba;
}

double Sensor::getHidingCoeff() const {
    return this->bestiole->getHidingCoeff();
}