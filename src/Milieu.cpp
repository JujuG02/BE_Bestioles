#include "Milieu.h"

#include <cstdlib>
#include <ctime>

const T Milieu::white[] = {(T)255, (T)255, (T)255};

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3),
                                          width(_width), height(_height)
{
    cout << "const Milieu" << endl;

    std::srand(time(NULL));
}

Milieu::~Milieu()
{
    cout << "dest Milieu" << endl;
}

void Milieu::addMember(Bestiole *b)
{
   listeBestioles.push_back(b); 
   listeBestioles.back()->initCoords(width, height);
}

void Milieu::step()
{
    double collidingDeathProb = 0.1;

    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);

    for (auto it = listeBestioles.begin(); it != listeBestioles.end();)
    {
        for (auto jt = it + 1; jt != listeBestioles.end();)
        {
            if ((*it)->isColliding(**jt))
            {
                if ((*jt)->collision(collidingDeathProb))
                {
                    jt = listeBestioles.erase(jt); // Erase from vector
                }
                else
                {
                    ++jt;
                }
                if ((*it)->collision(collidingDeathProb))
                {
                    it = listeBestioles.erase(it); // Erase from vector
                    break;
                }
            }
            else
            {
                ++jt;
            }
        }
        if (it != listeBestioles.end() && (*it)->deathByAge())
        {
            it = listeBestioles.erase(it); // Erase from vector
        }
        else if (it != listeBestioles.end())
        {
            (*it)->action(*this);
            (*it)->draw(*this);
            ++it;
        }
    }
}

int Milieu::nbVoisins(const Bestiole &b)
{
    int nb = 0;

    for (const auto bestiole : listeBestioles)
    {
        if (bestiole && !(b == *bestiole) && b.jeTeVois(*bestiole))
        {
            ++nb;
        }
    }

    return nb;
}

std::vector<Bestiole> Milieu::getVoisins(Bestiole* b)
{
    std::vector<Bestiole> voisins;
    for (const auto bestiole : listeBestioles)
    {
        if (bestiole && !(b == bestiole) && b->jeTeVois(*bestiole))
        {
            voisins.push_back(*bestiole); // Copy the Bestiole object
        }
    }

    return voisins;
}

