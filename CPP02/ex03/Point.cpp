#include "Point.hpp"

Point::Point()
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
