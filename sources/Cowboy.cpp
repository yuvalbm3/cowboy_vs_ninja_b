#include "Cowboy.hpp"
#include "Point.hpp"

namespace ariel
{
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110, false), _boolets_amount(6)
    {
    }

    void Cowboy::shoot(Character *enmy)
    {
        if (this == enmy)
        {
            throw std::runtime_error("You can't hurt yourself!");
        }
        else if (!this->isAlive())
        {
            throw std::runtime_error("Dead characters can't attack!");
        }
        else if (!enmy->isAlive())
        {
            throw std::runtime_error("Characters can't attack a dead enemy!");
        }
        else if (this->isAlive() && this->hasboolets())
        {
            this->_boolets_amount -= 1;
            enmy->hit(10);
        }
    }

    bool Cowboy::hasboolets()
    {
        return _boolets_amount > 0;
    }
    int Cowboy::booletNum()
    {
        return _boolets_amount;
    }

    void Cowboy::reload()
    {
        if (!this->isAlive())
        {
            throw std::runtime_error("Dead cowboy can't reload");
        }
        this->_boolets_amount = 6;
    }

    string Cowboy::print()
    {
        ostringstream os;
        if (this->_hp > 0)
        {

            os << "C - " << this->_name << ", " << this->_hp << ", " << this->_location << endl;
        }
        else
        {
            os << "C - (" << this->_name << "), " << this->_location << endl;
        }
        return os.str();
    }

}
