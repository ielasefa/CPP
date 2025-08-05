#include "Point.hpp"

Point::Point() : point_x(0), point_y(0) {}

Point::Point(const float x, const float y)
    : point_x(Fixed(x)), point_y(Fixed(y)) {}

Point::Point(const Point &other)
    : point_x(other.point_x), point_y(other.point_y) {}

Fixed Point::getX() const
{
    return this->point_x;
}

Fixed Point::getY() const
{
    return this->point_y;
}

Point &Point::operator=(const Point &src)
{
	if (this == &src)
		return *this;
	return *this;
}

Point::~Point() {}