#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
using namespace std;

namespace ariel{
    class Point{
        private:
        double _x, _y;
        public:
        Point(double, double);
        Point();
        Point(const Point&);
        double getX(){return this->_x;}
        double getY(){return this->_y;}
        void setX(Point);
        void setX(double);
        void setY(Point);
        void setY(double);
        double distance(Point);
        static Point moveTowards(Point, Point, double);
        bool operator==(const Point&) const;
    };
    ostream &operator<<(ostream &out, const Point &other);

}
#endif