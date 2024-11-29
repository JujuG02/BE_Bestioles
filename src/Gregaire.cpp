#include "Gregaire.h"
#include "Bestiole.h"
#include <numeric> 

void Gregaire::move(std::vector<Bestiole>& bestioleList, Bestiole& b) {
    // Vérifie si la liste des bestioles est vide
    if (bestioleList.empty()) return;
    double sumX = 0.0;
    double sumY = 0.0;

    // Parcourt chaque bestiole de la liste pour additionner leurs coordonnées 
    for (const auto& bestiole : bestioleList) {
        sumX += bestiole.getCumulX();
        sumY += bestiole.getCumulY();
    }

    // Calcule la moyenne des coordonnées 
    double avgX = sumX / bestioleList.size();
    double avgY = sumY / bestioleList.size();

    // Met à jour les coordonnées de la bestiole grégaire pour suivre la moyenne
    b.setCumulX(avgX);
    b.setCumulY(avgY);
}
