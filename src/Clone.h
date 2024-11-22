#ifndef _Clone_H_
#define _Clone_H_

#include "Bestiole.h"

class Bestiole;

class Clone {
    public :
        virtual Bestiole* clone() const =0;
};

#endif