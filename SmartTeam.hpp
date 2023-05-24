#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"



namespace ariel{
    class SmartTeam : public Team{
    public:
        SmartTeam(Character*);
        void attack(Team *other);
        void print() const;
    };
}

#endif