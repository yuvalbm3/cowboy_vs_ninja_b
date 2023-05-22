#include "Team2.hpp"
#include <iostream>
#include <limits>
#include <unistd.h>
using namespace std;

#define WARRIORS_LIM 10

namespace ariel{
    Team2::Team2(Character* leader): Team(leader){}

    void Team2::attack(Team *enmy)
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

        for (Character *mem : this->_members)
        {
            if(!vict->isAlive()){
                if(enmy->stillAlive() == 0){
                    break;
                }
                vict = closestToLeader(_leader, enmy);
            }
            Cowboy *c = dynamic_cast<Cowboy*>(mem);
            if(c != nullptr && c->isAlive()){
                if(!c->hasboolets()){
                    c->reload();
                }
                else{
                    // while(c->hasboolets()){
                        c->shoot(vict);
                    // }
                }
            }
            Ninja *n = dynamic_cast<Ninja*>(mem);
            if(n != nullptr && n->isAlive()){
                if(n->distance(vict) <= 1){
                    n->slash(vict);
                }
                else{
                    n->move(vict);
                }
            }
        }
    }
}