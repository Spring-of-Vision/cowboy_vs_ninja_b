#pragma once

#include <vector>
#include "Character.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"

namespace ariel
{ 
    class Team
    {
        //fields
        Character *leader;
        std::vector<Character*> fighters;

        //helper
        //bool sortByType(Character* a, Character* b);

        public:
            //constructors
            Team(Character *lead);
            ~Team();

            //methods
            void add(Character *fighter);
            void attack(Team *enemies);
            int stillAlive();
            void print();

            //public helper
            Character* getClosest(Character*);
    };
}