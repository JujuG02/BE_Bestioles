#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <vector>

using namespace std;

class Milieu : public UImg
{
private:
   static const T white[];

   int width, height;
   std::vector<Bestiole*> listeBestioles; // Changed to store pointers to Bestiole

public:
   Milieu(int _width, int _height);
   ~Milieu();

   int getWidth() const { return width; }
   int getHeight() const { return height; }

   void step();

   void addMember(Bestiole* b); // Changed parameter to Bestiole*
   int nbVoisins(const Bestiole& b);
   std::vector<Bestiole> getVoisins(Bestiole* b);
};

#endif
