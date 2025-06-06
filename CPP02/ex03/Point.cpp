#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	std::cout << "Point Default Constructor\n";
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	std::cout << "Point Default Constructor\n";
}

Point::Point(Point const &original) : _x(original._x), _y(original._y)
{
	std::cout << "Point Copy Constructor\n";
}

void Point::operator=(Point const &original)
{
	(void)original;
}

Point::~Point()
{
	std::cout << "Point Destructor\n";
}

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}
