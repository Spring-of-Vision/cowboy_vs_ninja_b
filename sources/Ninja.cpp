#include <stdio.h>
#include "Character.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace std;

namespace ariel
{   
    void Ninja::slash(Character *enemy)
    {
        if(this == enemy || !enemy->isAlive()|| enemy == nullptr)
            throw runtime_error("No self harm or attacking bodies and NO NULLPTRS");

        //if their distance is less than one space (meter)
        if(this->isAlive())
        {
            if(loc.distance(enemy->getLocation()) <= 1)
                enemy->hit(40);
        }
        else
        {
            throw runtime_error("Can't slash when dead");
        }
    }

    string Ninja::print()
    {
        //return a string with all info

        string output = "N ";

        if(hp > 0)
        {
            output = output + "Name: " + name + "\n";
            output = output + "HP: " + to_string(hp) + "\n";
        }
        else
        {
            output = output + "Name: (" + name + ")\n";
        }
        output = output + "Location: " + loc.print();

        return output;
    }

    void YoungNinja::move(Character *enemy)
    {
        if(this->isAlive())
            loc = Point::moveTowards(loc, enemy->getLocation(), speed);
        else
            throw runtime_error("Can't move when dead");
    }

    void TrainedNinja::move(Character *enemy)
    {
        if(this->isAlive())
            loc = Point::moveTowards(loc, enemy->getLocation(), speed);
        else
            throw runtime_error("Can't move when dead");
    }

    void OldNinja::move(Character *enemy)
    {
        if(this->isAlive())
            loc = Point::moveTowards(loc, enemy->getLocation(), speed);
        else
            throw runtime_error("Can't move when dead");
    }
}