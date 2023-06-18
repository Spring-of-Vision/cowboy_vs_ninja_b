#pragma once

#include "Character.hpp"

namespace ariel
{          
    class OldNinja : public Ninja
    {
        public:
            //constructors
            OldNinja(const std::string get_name, Point get_loc) : Ninja(get_name, get_loc) {speed = 8;hp = 150;};
            virtual void move(Character *enemy) override;
    };
}