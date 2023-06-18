#pragma once

#include "Character.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
        public:
            //constructors
            TrainedNinja(const std::string get_name, Point get_loc) : Ninja(get_name, get_loc){speed = 12;hp = 120;};
            virtual void move(Character *enemy) override;
    };
}