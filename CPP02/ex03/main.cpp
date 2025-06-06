#include "Point.hpp"
#include "Vector2.hpp"
#include <iostream>

enum	e_orientation
{
	negative = -1,
	parallel,
	positive
};

e_orientation sign(Fixed a)
{
	if (a < 0)
		return (negative);
	if (a > 0)
		return (positive);
	return (parallel);
}

const char *boolexpand(bool condition)
{
	return ((condition) ? "true" : "false");
}

Fixed	cross_product(Vector2 a, Vector2 b)
{
	return (a._x * b._y - b._x * a._y);
}

bool
	bsp(Vector2 const a,
		Vector2 const b,
		Vector2 const c,
		Vector2 const point)
{
	e_orientation orientation = sign(cross_product(b - a, c - a));
	return (sign(cross_product(b - a, point - a)) != -orientation
		&& sign(cross_product(c - b, point - b)) != -orientation
		&& sign(cross_product(a - c, point - c)) != -orientation);
}

int	main(void)
{
	Point const	a(4, 4);
	Point const	b(-4, 4);
	Point const c(4, -4);

	std::cout << "Triangle ABC " << a << ">" << b << ">" << c << " Contains the Point:\n";
	for (int i = -5; i <= 5; i++)
	{
		Point const p(i, i);
		std::cout << p << ": " << boolexpand(bsp(a, b, c, p)) << "\n";
	}
	return (0);
}
