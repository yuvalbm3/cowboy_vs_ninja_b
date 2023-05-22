#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <sstream>
#include <string.h>
#include "Point.hpp"

namespace ariel{
    class Character{
    private:
        ariel::Point _location;
        int _hp;
        string _name;
        bool _inTeam = false;
    public:
        Character(string name, Point loc, int hitPoint, bool inTeam):_location(loc), _name(name), _hp(hitPoint), _inTeam(inTeam){};
        virtual bool isAlive();
        virtual double distance(const Character*);
        virtual void hit(int);
        virtual string getName();
        virtual int getHp();
        virtual Point getLocation() const;
        virtual bool getInTeam();
        virtual void setInTeam(bool);
        virtual string print();
        //friends classes
        friend class Ninja;
        friend class Cowboy;
    };
}
#endif