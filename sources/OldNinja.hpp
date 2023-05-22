#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Character.hpp"
#include "Point.hpp"
#include "Ninja.hpp"
#include <sstream>

namespace ariel{
    class OldNinja : public Ninja{
        public:
            OldNinja(string name, Point loc);
    };
}

#endif
