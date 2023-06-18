#pragma once

#include "Team.hpp"

#define TEAMMATES 9

namespace ariel
{
    class Team2 : public Team
    {
        public:
            Team2(Character *lead) : Team(lead){};
        //override either helper function or attack/print
    };

    class SmartTeam : public Team
    {
        //override either helper function or attack/print
    }; 
}