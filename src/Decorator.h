#ifndef DECORATOR_H
#define DECORATOR_H

#include <vector>
#include "Bestiole.h"

class Decorator: public Bestiole {
    protected:
        Bestiole *bestiole;
    
    public:
        virtual void draw(UImg &support) = 0;

};

#endif