#include <stdio.h>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "Team.hpp"

using namespace std;

#define TEAMMATES 10

namespace ariel
{
    Team::Team(Character *lead) : leader(lead)
    {
        if(!leader->isAlive())
            throw runtime_error("Can't create team around a dead leader");
        else
            add(leader);
    }

    Team::~Team()
    {
        //delete anything that isn't already a nullptr
        for (Character* fighter : fighters)
        {   if(fighter)            
                delete fighter;
        }

    }

    void Team::add(Character *fighter)
    {
        if(fighter->getTaken() || fighter == nullptr)
        {
            throw runtime_error("Can't add a taken fighter and NO NULLPTRS");
        }
        
        if(fighters.size() < TEAMMATES)
        {
            fighters.push_back(fighter);
            fighter->setTaken(true);
            if(Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter))
            {
                sort(fighters.begin(), fighters.end(), [](Character* a, Character* b) {
                    if (dynamic_cast<Cowboy*>(a) && !dynamic_cast<Cowboy*>(b)) {
                        return true;  // Cowboys come before ninjas
                    }
                    return false;  // All other cases
                });
            }
        }
        else
        {
            throw runtime_error("Can't add more fighters to team");
        }
    }

    void Team::attack(Team *enemies)
    {
        if(enemies == nullptr || enemies == this)
            throw invalid_argument("NO NULLPTRS and no self-targetting");
        else if(!this->stillAlive() || !enemies->stillAlive())
            throw runtime_error("Either team is already dead");
            
        if(!leader->isAlive())
        {
            //find closest fighter and make him leader
            leader = getClosest(leader);
        }

        Character *victim = enemies->getClosest(leader);
        //all fighters attack: cowboys attack if have bullets, else reload. ninjas who are close enough will slash, else move closer
        //after every fighter attack, check if victim is alive and if not move to a new victim
        
        for(Character* fighter: fighters)
        {
            if(!fighter->isAlive())
                continue;

            if(Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter))
            {
                if(cowboy->hasboolets())
                    cowboy->shoot(victim);
                else   
                    cowboy->reload();
            }

            if(Ninja *ninja = dynamic_cast<Ninja *>(fighter))
            {
                if(ninja->distance(victim) <= 1)
                    ninja->slash(victim);
                else   
                    ninja->move(victim);
            }

            if(!victim->isAlive())
            {
                //active if to assign next victim
                if(!(victim = enemies->getClosest(leader))) //if nullptr, the opposing team is dead- function exits
                    return;
            }
        }
    }

    int Team::stillAlive()
    {
        //iterate over the fighters and count those still alive
        int count = 0;
        for(Character* fighter: fighters)
        {
            if(fighter->isAlive())
                count++;
        }
        return count;
    }

    void Team::print()
    {
        //iterate over the fighters and print their stats
        for(Character* fighter: fighters)
        {
            cout << fighter->print();
        }
    }

    Character* Team::getClosest(Character* origin)
    {
        Character* result = nullptr;
        double closest = __DBL_MAX__;
        //find closest enemies fighter to our leader- that is the victim
        for(Character* fighter: fighters)
        {
            if(fighter->isAlive() && fighter->distance(origin) < closest)
            {
                closest = fighter->distance(origin);
                result = fighter;
            }
        }

        return result;
    }
}