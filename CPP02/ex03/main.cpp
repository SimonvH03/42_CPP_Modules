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

Fixed	cross_product(Vector2 a, Vector2 b)
{
	return (a._x * b._y - b._x * a._y);
}

// evaluate if P is on the same side of AB as C
// same for P and B with line AC, etc.
// if any fails, return (false), otherwise continue
// until three sides are checked
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
	Point const	a(0,0);
	Point const	b(1,0);
	Point const c(0,1);

	Point const p(0,0);

	std::cout << bsp(a, b, c, p) << std::endl;
	return (true);
}
