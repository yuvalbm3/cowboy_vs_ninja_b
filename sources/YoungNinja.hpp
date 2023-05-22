#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Character.hpp"
#include "Point.hpp"
#include "Ninja.hpp"
#include <sstream>

namespace ariel{
    class YoungNinja : public Ninja{
        public:
            YoungNinja(string name, Point loc);
    };
}

#endif
