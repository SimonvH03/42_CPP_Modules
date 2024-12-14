#include "Fixed.hpp"
# include <iostream>

void	announce(std::string const &name, std::string const &func)
{
	std::cout << "called:\t\e[32m"
		<< std::setw(27) << name
		<< "\e[0m\t" << func << "\n";
}

int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	a.setRawBits(42);
	b.setRawBits(7);
	c.setRawBits(-1);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
