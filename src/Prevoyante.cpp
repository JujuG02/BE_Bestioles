#include "Prevoyante.h"
#include "Behavior.h"
#include "Bestiole.h"
#include <cmath>
#include <vector>

void Prevoyante::move(std::vector<Bestiole> &bestioleList, Bestiole& b) {

    // Mise de couleur standard pour les peureuses (vert)
    if (b.getCouleur()[0] != 255 || b.getCouleur()[1] != 255 || b.getCouleur()[2] != 0) {
        T* couleur = new T[3];
        couleur[0] = 255;
        couleur[1] = 255;
        couleur[2] = 0;

        b.setCouleur(couleur);
    }

    const int ROWS = bestioleList.size();
    const int COLUMNS = 2;

    if(!bestioleList.empty()){
        //tableau pour stocker les positions des voisins
        std::vector<std::vector<double>> positionFuturVosins(ROWS, std::vector<double>(COLUMNS, 0));

        int id = 0;

        //prévision de la trajectoire des voisins au prochain step
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

        /**On calcul le barycentre pour être sur de ne pas faire de collisions
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
        

        //calcul de l'orientation pour atteindre cette position
        double dx = barycentreX - b.getX();
        double dy = barycentreY - b.getY();
        double orientation = atan2(-dy, dx);
        if (dx == 0 && dy == 0) {
            orientation = b.getOrientation(); // Maintenir l'orientation actuelle
        } else {
            orientation = atan2(-dy, dx);
        }
        b.setOrientation(orientation);

        //calcul de la vitesse pour atteindre cette position
        double distance = sqrt(dx * dx + dy * dy);
        double vitesse = distance ; 
        b.setVitesse(vitesse);
    }
}

