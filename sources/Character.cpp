#include <stdio.h>
#include "Character.hpp"

using namespace std;

namespace ariel
{
    void Character::hit(int pts)
    {
        if(pts <= 0)
            throw invalid_argument("Can't hit negative or zero points");
        else
            hp-=pts;
    }

    double Character::distance(Character *other)
    {
        return this->loc.distance(other->loc);
    }

    void Character::setTaken(bool input)
    {
        inTeam = input;
    }

    bool Character::getTaken()
    {
        return inTeam;
    }
}