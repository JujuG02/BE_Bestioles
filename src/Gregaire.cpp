#include "Gregaire.h"
#include "Bestiole.h"
#include <cmath>

/*
 * Comportement grégaire : la bestiole ajuste sa direction sur la direction moyenne des bestioles environnantes.
 */



void Gregaire::move(std::vector<Bestiole>& bestioleList, Bestiole& b) {
    //Mise de couleur standard pour les gregaires
    if(b.getCouleur()[0] != 128 || b.getCouleur()[1] != 128 || b.getCouleur()[2] != 128){
        T* couleur = new T[3];
        couleur[0] = 128;
        couleur[1] = 128;
        couleur[2] = 128;

        b.setCouleur(couleur);
    }

    // Si la liste des bestioles est vide, on quitte la fonction
    if (bestioleList.empty()) return;

    double sumOrientation = 0.0;
    int count = 0;

    // Calcul de la somme des orientations des bestioles environnantes
    for (const auto& bestiole : bestioleList) {
        sumOrientation += bestiole.getOrientation();
        count++;
    }

    // Calculer l'orientation moyenne
    double avgOrientation = sumOrientation / count;

    // Ajuster l'orientation de la bestiole à l'orientation moyenne
    b.setOrientation(avgOrientation);

    // Mise à jour de cumulX et cumulY
    b.setCumulX(std::cos(avgOrientation) * b.getVitesse());
    b.setCumulY(-std::sin(avgOrientation) * b.getVitesse());
}
