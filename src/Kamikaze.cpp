#include "Kamikaze.h"
#include "Behavior.h"
#include "Bestiole.h"
#include <limits>
#include <iostream>
#include <cmath>

/*
Methode pour faire bouger la bestiole selon un comportement kamikaze : changer d'orientation pour provoquer une collision avec 
la bestiole la plus proche.
Cette methode est appelée à chaque step de la simulation et n'agit que sur l'orientation et la vitesse de la bestiole.

Elle prend en paramètre :
    - un vecteur des bestioles que la kamikaze voit
    - Et la bestiole en elle même

*/ 
void Kamikaze::move(std::vector<Bestiole> &bestioleList, Bestiole &b) {
    
    //multiplicateur de vitesse lorsque la proie de la bestiole est repérée
    const double VITESSE_MULTIPLIER = 10;

    // Mise de couleur standard pour les kamikazes (rouge)
    if (b.getCouleur()[0] != 255 || b.getCouleur()[1] != 0 || b.getCouleur()[2] != 0) {
        T* couleur = new T[3];
        couleur[0] = 255;
        couleur[1] = 0;
        couleur[2] = 0;

        b.setCouleur(couleur);
    }

    // on vérifie que la liste des voisins n'est pas vide
    if (bestioleList.empty()) return;

    /*
        On trouve la bestiole là plus proche
    */
    //initialisation de la distance minimale et de la bestiole comme dans un calcul de minimum classique
    double minDist = std::numeric_limits<double>::infinity();
    Bestiole* closeBestiole = &bestioleList[0];

    for(std::vector<Bestiole>::iterator it = bestioleList.begin(); it != bestioleList.end(); ++it){
    // Ignorer la bestiole elle-même
        if (&(*it) == &b) continue;

    // Calculer la distance par rapport à la bestiole
        double dx = b.getX() - it->getX();
        double dy = b.getY() - it->getY();
        double dist = sqrt(dx * dx + dy * dy);

        if(minDist> dist){//on choisi le plus proche voisin
            minDist = dist;
            closeBestiole = &(*it);
        }
    }

    //calcul de l'orientation par rapport au plus proche vosin
    double dx = closeBestiole->getX() - b.getX();
    double dy = closeBestiole->getY() - b.getY();
    double orientation = atan2(-dy, dx);

    //changement des attribut de la bestiole kamikaze
    b.setOrientation(orientation);
    b.setVitesse(VITESSE_MULTIPLIER*closeBestiole->getVitesse());
    }

