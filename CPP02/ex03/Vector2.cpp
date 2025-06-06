#include "Vector2.hpp"

Vector2::Vector2(): _x(0), _y(0)
{
	std::cout << "Vector2 Default Constructor\n";
}

Vector2::Vector2(Fixed x, Fixed y): _x(x), _y(y)
{
	std::cout << "Vector2 Fixed Constructor\n";
}

Vector2::Vector2(Vector2 const &original)
{
	std::cout << "Vector2 Copy Constructor\n";
	*this = original;
}

Vector2 &Vector2::operator=(Vector2 const &original)
{
	std::cout << "Vector2 Assignment Operator\n";
	if (this != &original)
	{
		_x = original._x;
		_y = original._y;
	}
	return (*this);
}

Vector2::Vector2(Point const &original)
{
	std::cout << "Vector2 Point Constructor\n";
	*this = original;
}

Vector2 &Vector2::operator=(Point const &original)
{
	std::cout << "Vector2 Assignment Operator\n";
	_x = original.getX();
	_y = original.getY();
	return (*this);
}

Vector2	Vector2::operator-(Vector2 const &num) const
{
	Vector2	result(*this);
	result._x -= num._x;
	result._y -= num._y;
	return (result);
}

Vector2::~Vector2()
{
	std::cout << "Vector2 Destructor\n";
}
