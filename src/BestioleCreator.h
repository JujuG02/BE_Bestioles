#ifndef _BESTIOLECREATOR_H_
#define _BESTIOLECREATOR_H_

#include "Bestiole.h"
#include "Creator.h"
#include "Decorator.h"
#include "Behavior.h"

class BestioleCreator : public Creator {
    public :
        Bestiole* create() const override;
}





#endif