#include "Team.hpp"
#include <iostream>
#include <limits>
#include <unistd.h>
#include <vector>
using namespace std;

#define WARRIORS_LIM 10

namespace ariel
{
    Team::Team(Character *leader)
    {
        if (this->_members.size() > 0)
        {
            throw std::runtime_error("The team has already been initialized...");
        }
        else if (leader->getInTeam())
        {
            throw std::runtime_error("This player already in other team...");
        }
        else
        {
            this->_leader = leader;
            team_size++;
            leader->setInTeam(true);
            _members.push_back(leader);
        }
    }

    Team::~Team()
    {
        for (Character *mem : _members)
        {
            delete mem;
        }
        _members.clear();
    }

    void Team::add(Character *other)
    {
        if (this->_leader == NULL)
        {
            throw invalid_argument("You need to initialized the team first..");
        }
        else if (other->getInTeam())
        {
            throw std::runtime_error("This palyer in other team already.");
        }
        else if (this->team_size >= 10)
        {
            throw std::runtime_error("The team get to it's maximum capacity..");
        }
        else
        {
            _members.push_back(other);
            other->setInTeam(true);
            team_size++;
        }
    }

    void Team::attack(Team *enmy)
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
        if (!this->getLeader()->isAlive())
        {
            this->setLeader(closestToLeader(_leader, this));
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
                    c->shoot(vict);
                }
            }
        }
        for (Character *mem : this->_members)
        {
            if(!vict->isAlive()){
                if(enmy->stillAlive() == 0){
                    exit(0);
                }
                vict = closestToLeader(_leader, enmy);
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

    Character *Team::closestToLeader(Character *leader, Team *team)
    {
        Character *temp;
        double minDis = std::numeric_limits<double>::max();
        for (Character *mem : team->_members)
        {
            if (mem == leader || !mem->isAlive())
            {
                continue;
            }
            else if (leader->distance(mem) < minDis)
            {
                minDis = leader->distance(mem);
                temp = mem;
            }
        }
        return temp;
    }

    int Team::stillAlive() const
    {
        int st_live = 0;
        for(Character* mem: _members){
            if(mem->isAlive()){
                st_live++;
            }
        }
        return st_live;
    }

    Character* Team::getLeader() const{
        return _leader;
    }

    void Team::setLeader(Character* new_leader){
        _leader = new_leader;
    }
    
    int Team::getSize() const
    {
        return team_size;
    }

    void Team::print()
    {
        string st = "";
        for (Character *mem : this->_members)
        {
            Cowboy *c = dynamic_cast<Cowboy*>(mem);
            if(c != nullptr){
                st += mem->print();
            }
        }
        for (Character *mem : this->_members)
        {
            Ninja *n = dynamic_cast<Ninja*>(mem);
            if(n != nullptr && n->isAlive()){
                st += mem->print();
            }
        }
        cout << st << endl;
    }
}