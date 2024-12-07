#include "Prevoyante.h"
#include "Behavior.h"
#include "Bestiole.h"
#include <cmath>
#include <vector>

/*
Methode pour faire bouger la bestiole selon un comportement prévoyant : essaye de prévoir le comportement de ses 
voisins et d'éviter les collisions avec ceux-ci.
Cette methode est appelée à chaque step de la simulation et n'agit que sur l'orientation et la vitesse de la bestiole.

Elle prend en paramètre :
    - un vecteur des bestioles que la kamikaze voit
    - Et la bestiole en elle même

Cette methode ne prend pas en compte les comportement des voisins ce qui rend la prévoyante peut efficace pour éviter ses voisins.
Elle part du principe que ses voisins ont un comportement banal.
*/ 

void Prevoyante::move(std::vector<Bestiole> &bestioleList, Bestiole& b) {

    // Mise de couleur standard pour les prévoyante (jaune)
    if (b.getCouleur()[0] != 255 || b.getCouleur()[1] != 255 || b.getCouleur()[2] != 0) {
        T* couleur = new T[3];
        couleur[0] = 255;
        couleur[1] = 255;
        couleur[2] = 0;

        b.setCouleur(couleur);
    }

    //réalisation d'un tableau pour stocker les positions de ses voisins 
    const int ROWS = bestioleList.size();
    const int COLUMNS = 2;

    if(!bestioleList.empty()){//on vérifie que la liste des bestioles qu'elle voit n'est vide.

        //tableau pour stocker les positions des voisins
        std::vector<std::vector<double>> positionFuturVosins(ROWS, std::vector<double>(COLUMNS, 0));

        int id = 0;

        /*prévision de la trajectoire des voisins au prochain step
        Nous le faisons de la même manière qu'opère la methode Bestiole.bouge()
        */
        for(std::vector<Bestiole>::iterator voisin = bestioleList.begin(); voisin != bestioleList.end(); ++voisin){
            double         nx, ny;
            double         dx = cos( voisin->getOrientation() )*voisin->getVitesse();
            double         dy = -sin(voisin->getOrientation())*voisin->getVitesse();
            int            cx, cy;
            cx = static_cast<int>( voisin->getCumulX()); 
            cy = static_cast<int>(voisin->getCumulY());
            nx = voisin->getX() + dx + cx;
            ny = voisin->getY() + dy + cy;

            positionFuturVosins[id][0] = nx;
            positionFuturVosins[id][1] = ny;

            id+=1;
        }

        /**
            On calcul le barycentre pour être sur de ne pas faire de collisions
        */
        // Calcul des sommes des coordonnées x et y
        double sumX = 0.0, sumY = 0.0;
        for (int i = 0; i < ROWS; ++i) {
            sumX += positionFuturVosins[i][0]; 
            sumY += positionFuturVosins[i][1];
        }

        // Calcul du barycentre, qui est la position souhaité au prochain step
        if (ROWS == 0) {return;}
        double barycentreX = sumX / ROWS;
        double barycentreY = sumY / ROWS;
        

        //Calcul de l'orientation pour atteindre la position du barycentre
        double dx = barycentreX - b.getX();
        double dy = barycentreY - b.getY();
        double orientation = atan2(-dy, dx);
        if (dx == 0 && dy == 0) {
            orientation = b.getOrientation(); // Maintenir l'orientation actuelle
        } else {
            orientation = atan2(-dy, dx);
        }
        b.setOrientation(orientation);

        //calcul de la vitesse pour atteindre le barycentre position au prochain step
        double distance = sqrt(dx * dx + dy * dy);
        double vitesse = distance/30 ; 
        b.setVitesse(vitesse);
    }
}

