#pragma once

#include <iostream>
#include "Point.hpp"

namespace ariel
{ 
    class Character
    {
        //fields
        protected:
            Point loc;
            int hp;
            std::string name;
            bool inTeam;

        public:
            //constructors
            Character(std::string get_name, Point get_loc) : name(get_name), loc(get_loc){ inTeam = false;};

            //destructor
            virtual ~Character() = default;

            //methods
            bool isAlive(){return (hp > 0);};
            double distance(Character *other);
            void hit(int pts);
            std::string getName(){return name;};
            Point& getLocation(){return loc;};
            virtual std::string print() = 0;
            void setTaken(bool);
            bool getTaken();
    };

    class Ninja : public Character
    {
        protected:
            //fields
            int speed;

        public:
            //constructors
            Ninja(const std::string get_name, Point get_loc) : Character(get_name, get_loc){};

            //methods
            virtual void move(Character *enemy) = 0;
            void slash(Character *enemy);
            virtual std::string print() override;
    };
}