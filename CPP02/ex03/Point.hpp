#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
		void operator=(Point const &original);

	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &original);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

#endif
