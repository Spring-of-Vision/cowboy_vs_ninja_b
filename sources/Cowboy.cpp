#include <stdio.h>
#include "Cowboy.hpp"

using namespace std;

namespace ariel
{
    void Cowboy::reload()
    {
        if(hp <= 0)
            throw runtime_error("Can't reload when dead");
        else
            bullets = 6;
    }

    void Cowboy::shoot(Character *enemy)
    {
        if(this == enemy || !enemy->isAlive() || enemy == nullptr)
            throw runtime_error("No self harm or attacking bodies and NO NULLPTRS");

        if(this->isAlive())
        {
            if(this->hasboolets())
                enemy->hit(10);
            bullets--;
        }
        else
        {
            this->loc.print();
            throw runtime_error("Can't shoot when dead");
        }
    }

    string Cowboy::print()
    {
        //return a string with all info

        string output = "C ";

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
}