#include "Gregaire.h"
#include "Bestiole.h"
#include <numeric> 

void Gregaire::move(std::vector<Bestiole> &bestioleList) {
    if (bestioleList.empty()) return;
    double sumX = 0.0;
    double sumY = 0.0;

    for (const auto &b : bestioleList) {
        sumX += b.getCumulX();
        sumY += b.getCumulY();
    }

    double avgX = sumX / bestioleList.size();
    double avgY = sumY / bestioleList.size();

    this->cumulX = avgX;
    this->cumulY = avgY;
}
