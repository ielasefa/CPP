#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed point_x;
        const Fixed point_y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &other);
        Point &Point::operator=(const Point &src);
        Fixed getX() const;
        Fixed getY() const;
        ~Point();
};

#endif