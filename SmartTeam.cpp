#include "SmartTeam.hpp"
#include <iostream>
#include <limits>
#include <unistd.h>
using namespace std;

#define WARRIORS_LIM 10

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    void SmartTeam::attack(Team *enmy)
    {
        if (enmy == nullptr)
        {
            throw std::invalid_argument("Enemy can't be nullptr.");
        }
        else if (enmy == this)
        {
            throw std::runtime_error("Team can't attack itself.");
        }
        else if (enmy->stillAlive() == 0)
        {
            throw std::runtime_error("The enemy team is dead.");
        }
        else if (this->stillAlive() == 0)
        {
            throw std::runtime_error("The team is dead.");
        }
        if (!this->_leader->isAlive())
        {
            _leader = closestToLeader(_leader, this);
        }
        Character *vict = closestToLeader(_leader, enmy);

        int cowboy_num = 0;
        int ninja_num = 0;

        for (Character *mem : this->_members){
            Cowboy *c = dynamic_cast<Cowboy *>(mem);
            if (c != nullptr && c->isAlive()){
                cowboy_num++;
            }
            Ninja *n = dynamic_cast<Ninja *>(mem);
            if (n != nullptr && n->isAlive()){
                ninja_num++;
            }
        }

        int for_index = 0;

        for (Character *mem : this->_members)
        {   
            for_index++;
            if (!vict->isAlive())
            {
                if (enmy->stillAlive() == 0)
                {
                    break;
                }
                vict = closestToLeader(_leader, enmy);
            }
            else if((vict->getHp() < cowboy_num * 10) || this->getSize() - for_index == cowboy_num){
                Cowboy *c = dynamic_cast<Cowboy *>(mem);
                if (c != nullptr && c->isAlive())
                {
                    if (!c->hasboolets())
                    {
                        c->reload();
                    }
                    else
                    {
                        c->shoot(vict);
                    }
                }
            }

            Ninja *n = dynamic_cast<Ninja *>(mem);
            if (n != nullptr && n->isAlive())
            {
                if (n->distance(vict) <= 1)
                {
                    n->slash(vict);
                }
                else
                {
                    n->move(vict);
                }
            }
        }
    }

    void SmartTeam::print() const
    {
        string st = "";
        for(Character* mem:_members){
            st += mem->print();
        }
        cout << st << endl;
    }
}