#include "Fixed.hpp"
# include <iostream>

int	main(void)
{
	Fixed		a;
	Fixed		b(5.1f);
	Fixed		c(3.15f);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	a = b;
	std::cout << a << std::endl;
	a += c;
	std::cout << a << std::endl;
	a *= b;
	std::cout << a << std::endl;
	a /= b;
	std::cout << a << std::endl;

	return (0);
}
