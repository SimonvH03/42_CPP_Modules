#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	std::cout << "Point Default Constructor\n";
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	std::cout << "Point Default Constructor\n";
}

Point::Point(Point const &original)
{
	std::cout << "Point Copy Constructor\n";
	*this = original;
}

Point &Point::operator=(Point const &original)
{
	std::cout << "Point Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

Point::~Point()
{
	std::cout << "Point Destructor\n";
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	return (false);
	return (true);
}
