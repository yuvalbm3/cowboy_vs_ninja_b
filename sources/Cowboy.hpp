#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <sstream>

namespace ariel{
    class Cowboy : public Character{
    private:
        int _boolets_amount;
    public:
        Cowboy(string name, Point location);
        void shoot(Character *enmy);
        bool hasboolets();
        int booletNum();
        void reload();
        string print();
    };
    
}

#endif
