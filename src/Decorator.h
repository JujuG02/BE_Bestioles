#ifndef DECORATOR_H
#define DECORATOR_H

#include <vector>

class Decorator {
    public:
        virtual void draw() = 0;
        virtual ~Decorator() = default;
        virtual void draw(UImg &support, double x, double y, double orientation) = 0;

};

#endif