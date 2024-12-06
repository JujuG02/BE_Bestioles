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
    this->detectionProb = MIN_DETEC_PROB + static_cast<double>(rand()) / RAND_MAX * (MAX_DETEC_PROB - MIN_DETEC_PROB);
    this->bestiole = &b;
}

Sensor::Sensor(Sensor const &s){
    this->range = s.range;
    this->detectionProb = s.detectionProb;
    this->fov = s.fov;
    this->bestiole = s.bestiole->clone();
    std::cout<<"copie s"<<std::endl;
}

Sensor& Sensor::operator=(Sensor const &s){
    if(this != &s){
        this->range = s.range;
        this->detectionProb = s.detectionProb;
        this->fov = s.fov;
        this->bestiole = s.bestiole->clone();
    }
    std::cout<<"affect s"<<std::endl;
    return *this;
}

Sensor* Sensor::clone() const {
    std::cout<<"clone s"<<std::endl;
    return new Sensor(*this);
}
Sensor::~Sensor(){
    delete this->bestiole;
}

void Sensor::draw(UImg &support) {
    // Implémentation spécifique du sensor
    this->bestiole->draw(support);
}

bool Sensor::jeTeVois(const Bestiole &b) const{
    int bx = b.getX();
    int by = b.getY();
    double dist = std::sqrt( (this->x - bx)*(this->x - bx) + (this->y - by)*(this->y - by) );
    double angle = std::atan2(by - this->y, bx - this->x);

    bool detecable = dist<=this->range
        && std::abs(angle - this->bestiole->getOrientation()) <= this->fov/2;
    
    double randomValue = static_cast<double>(rand()) / RAND_MAX;
    double detectionProba = this->detectionProb;
    const Camouflage* camo = dynamic_cast<const Camouflage*>(&b);
    if (camo) {
        double hidingCoeff = camo->getHidingCoeff();
        detectionProba = detectionProba * hidingCoeff;
    }

    return detecable && randomValue < detectionProba;
}