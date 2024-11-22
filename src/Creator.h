#ifndef _CREATOR_H_
#define _CREATOR_H_

#include "Bestiole.h"

class Creator {
    public :
        virtual Bestiole* create() const = 0;
};




#endif