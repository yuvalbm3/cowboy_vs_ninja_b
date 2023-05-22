#include <math.h>
#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel{

    Point::Point(double x, double y):_x(x), _y(y){}
    Point::Point(){
        _x = 0;
        _y = 0;
    }
    Point::Point(const Point &other){
        _x = other._x;
        _y = other._y;
    }


    double Point::distance(Point p){
        double dis_x = this->_x - p.getX();
        double dis_y = this->_y - p.getY();
        double ans = sqrt(pow(dis_x,2)+pow(dis_y,2)*1.0);
        return ans; 
    }
    
    Point Point::moveTowards(Point src, Point dst, double dis){
        if(dis < 0){
            throw invalid_argument("Distance can't be negative..");
        }
        double src2dist = src.distance(dst);
        if(src2dist <= dis){
            return dst;
        }
        else{
            double dx = dst._x - src._x;
            double dy = dst._y - src._y;

            double moveX = (dis * dx / src2dist) + src._x;
            double moveY = (dis * dy / src2dist) + src._y;
            return Point(moveX, moveY);
        }
    }

    void Point::setX(Point other){
        _x = other.getX();
    }

    void Point::setX(double other){
        _x = other;
    }

    void Point::setY(Point other){
        _y = other.getY();
    }

    void Point::setY(double other){
        _y = other;
    }

    bool Point::operator==(const Point& other) const{
        return (_x == other._x && _y == other._y);
    }

    ostream &operator<<(ostream &out, const Point &other)
    {
        Point res = other;
        out << to_string(res.getX()) << "/" << to_string(res.getY());
        return out;
    }
}