#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>

class Point
{
	private:

	protected:

	public:
		Point();
		Point(Point const &original);
		Point &operator=(Point const &original);
		~Point();
};

#endif
