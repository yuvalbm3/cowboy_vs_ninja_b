#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include "Point.hpp"
#include <sstream>

namespace ariel{
    class Ninja : public Character{
    private:
        int _speed;
    public:
        Ninja(string name, Point loc, int hp, bool inTeam, int speed);
        
        void move(Character *enmy);
        
        void slash(Character *enmy);
        
        int getSpeed();

        string print();
    };

}

#endif
