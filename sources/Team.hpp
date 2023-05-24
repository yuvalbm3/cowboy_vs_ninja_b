#ifndef TEAM_HPP
#define TEAM_HPP


#include <vector>
#include"YoungNinja.hpp"
#include"TrainedNinja.hpp"
#include"OldNinja.hpp"
#include"Cowboy.hpp"


namespace ariel{
    class Team{
    private:
        Character* _leader;
        vector<Character *> _members;
        int team_size = 0;
    public:
        Team(Character* leader);
        virtual ~Team();
        Team(const Team& other);
        void add(Character*);
        int stillAlive() const;
        int getSize() const;
        Character* getLeader() const;
        void setLeader(Character*);
        Character* closestToLeader(Character*, Team*);
        virtual void attack(Team* other);
        virtual void print();
        friend class Team2;
        friend class SmartTeam;
    };
}

#endif