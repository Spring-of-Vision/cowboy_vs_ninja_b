#pragma once

#include "Character.hpp"

namespace ariel
{ 
    class Cowboy : public Character
    {
        //fields
        int bullets;

        public:
            //constructors
            Cowboy(std::string get_name, Point get_loc) : bullets(6), Character(get_name, get_loc){ hp = 110;};

            //methods
            void shoot(Character *enemy);
            bool hasboolets(){return (bullets > 0);};
            void reload();
            virtual std::string print() override;
    };
           
}