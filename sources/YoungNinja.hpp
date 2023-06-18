#pragma once

#include "Character.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
        public:
            //constructors
            YoungNinja(const std::string get_name, Point get_loc) : Ninja(get_name, get_loc){speed = 14;hp = 100;};
            virtual void move(Character *enemy) override;
    };
}