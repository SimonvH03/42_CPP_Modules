#include "Vector2.hpp"

Vector2::Vector2(): _x(0), _y(0)
{
}

Vector2::Vector2(Fixed x, Fixed y): _x(x), _y(y)
{
}

Vector2::Vector2(Vector2 const &original)
{
	*this = original;
}

Vector2 &Vector2::operator=(Vector2 const &original)
{
	if (this != &original)
	{
		_x = original._x;
		_y = original._y;
	}
	return (*this);
}

Vector2::Vector2(Point const &original)
{
	*this = original;
}

Vector2 &Vector2::operator=(Point const &original)
{
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
}
