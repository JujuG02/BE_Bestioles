#ifndef DECORATOR_H
#define DECORATOR_H

#include <vector>
#include "Bestiole.h"

/*
* Cette classe est une classe abstraite qui permet de décorer une bestiole.
* Elle est utilisée pour ajouter des fonctionnalités à une bestiole sans modifier son code.
* Son utilisation peut être vue comme si on embriquait des poupées russes, 
* chaque poupée représentant une décoration de la bestiole.
*/

class Decorator: public Bestiole {
    protected:
        Bestiole *bestiole;
    
    public:
        virtual ~Decorator() override = default;

        void PrintMemory() override {
            std::cout<<"Decorator "<<this<<std::endl;
            this->bestiole->PrintMemory();
        }

};

#endif