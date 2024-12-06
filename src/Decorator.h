#ifndef DECORATOR_H
#define DECORATOR_H

#include <vector>
#include "Bestiole.h"

class Decorator: public Bestiole {
    protected:
        Bestiole *bestiole;
    
    public:
        virtual ~Decorator() override = default;
        virtual void draw(UImg &support) = 0;

        void PrintMemory() override {
            std::cout<<"Decorator "<<this<<std::endl;
            this->bestiole->PrintMemory();
        }

};

#endif