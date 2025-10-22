#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(Point const &original) : _x(original._x), _y(original._y)
{
}

void Point::operator=(Point const &original)
{
	(void)original;
}

Point::~Point()
{
}

Fixed Point::getX()
const
{
	return (_x);
}

Fixed Point::getY()
const
{
	return (_y);
}

std::ostream	&operator<<(std::ostream &os, Point const &fixed)
{
	os << "(" << fixed.getX() << ", " << fixed.getY() << ")";
	return (os);
}
