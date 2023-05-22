#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"


namespace ariel{
    class Team2 : public Team{
    public:
        Team2(Character* leader);
        void attack(Team *other);
        void print() const;
    };
}

#endif