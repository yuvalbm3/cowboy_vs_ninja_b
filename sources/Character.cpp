#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <string.h>
using namespace std;

namespace ariel{
    bool Character::isAlive(){
        if((this->_hp) > 0)
            return true;
        return false;
    }
    double Character::distance(const Character *other){
        double ans = this->_location.distance(other->getLocation());
        return ans;
    }
    void Character::hit(int num){
        if(num < 0){
            throw std::invalid_argument("Hit can't be negative number.");
        }
        _hp = _hp - num;
    }
    string Character::getName(){
        return _name;
    }
    Point Character::getLocation() const{
        return _location;
    }
    int Character::getHp(){
        return _hp;
    }
    bool Character::getInTeam(){
        return _inTeam;
    }
    void Character::setInTeam(bool ans){
        this->_inTeam = ans;
    }
    string Character::print(){
        ostringstream os;
        Cowboy *c = dynamic_cast<Cowboy*>(this);
        if(c != nullptr && c->isAlive()){
            if(_hp>0){
                os << "C- " << _name << ", " << _hp << ", " << _location << endl;
            }
            else{
                os << "C - (" << _name << "), " << _location << endl;
            }
        }
        Ninja *n = dynamic_cast<Ninja*>(this);
        if(n != nullptr && n->isAlive()){
            if(_hp>0){
                os << "N - " << _name << ", " << _hp << ", " << _location << endl;
            }
            else{
                os << "N - (" << _name << "), " << _location << endl;
            }
        }
        return os.str();
    }
}