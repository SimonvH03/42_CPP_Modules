#ifndef VECTOR2_HPP
# define VECTOR2_HPP
# include <iostream>

# include "Fixed.hpp"
# include "Point.hpp"

class Vector2
{
	public:
		Fixed _x;
		Fixed _y;

		Vector2();
		Vector2(Fixed x, Fixed y);
		Vector2(Vector2 const &original);
		Vector2 &operator=(Vector2 const &original);
		Vector2(Point const &original);
		Vector2 &operator=(Point const &original);
		~Vector2();

		Vector2 operator-(Vector2 const &num) const;
};

#endif
