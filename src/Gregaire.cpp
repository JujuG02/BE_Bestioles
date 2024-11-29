
#include "Gregaire.h"
#include "Bestiole.h"
#include <cmath>

/*
 * Comportement grégaire : la bestiole ajuste son orientation et vitesse sur la moyenne des bestioles environnantes
 */
void Gregaire::move(std::vector<Bestiole>& bestioleList, Bestiole& b) {
    if (bestioleList.empty()) return;

    double sumOrientation = 0.0;

    for (const auto& bestiole : bestioleList) {
        sumOrientation += bestiole.getOrientation();
    }

    double avgOrientation = sumOrientation / bestioleList.size();

    b.setOrientation(avgOrientation);

    b.setCumulX(std::cos(b.getOrientation()) * b.getVitesse());
    b.setCumulY(-std::sin(b.getOrientation()) * b.getVitesse());
}
