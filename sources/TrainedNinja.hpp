#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Character.hpp"
#include "Point.hpp"
#include "Ninja.hpp"
#include <sstream>

namespace ariel{
    class TrainedNinja : public Ninja{
        public:
            TrainedNinja(string name, Point loc);
    };
}

#endif
