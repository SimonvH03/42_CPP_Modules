#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &original);
		Point &operator=(Point const &original);
		~Point();

		bool
			bsp(Point const a,
				Point const b,
				Point const c,
				Point const point);
};

#endif
