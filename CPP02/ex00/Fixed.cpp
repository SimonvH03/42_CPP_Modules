#include "Fixed.hpp"

void	Fixed::announce(std::string const &name, std::string const &func) const
{
	std::cout << "called:\t\e[32m"
		<< std::setw(27) << name
		<< "\e[0m\t" << func << "\n";
}

Fixed::Fixed()
{
	announce("Default Constructor", "Fixed::Fixed()");

	this->numberValue = 0;
}

Fixed::Fixed(Fixed const &src)
{
	announce("Copy Constructor", "Fixed::Fixed(Fixed const &src)");

	*this = src;
}

/*
	Note while both implementations of the Default Constructor are correct,
	one is probably prefered by 42, as it produces the output shown in Subject
*/
/*Fixed::Fixed(Fixed const &src)
{
	announce("Copy Constructor", "Fixed::Fixed(Fixed const &src)");

	this->numberValue = src.numberValue;
}*/

Fixed	&Fixed::operator=(Fixed const &src)
{
	announce("Copy assignment operator", "Fixed  &Fixed::operator=(Fixed const &src)");

	if (this != &src)
	{
		this->numberValue = src.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	announce("Destructor", "Fixed::~Fixed()");
}

int	Fixed::getRawBits() const
{
	announce("getRawBits member function", "int    Fixed::getRawBits() const");

	return (this->numberValue);
}

void	Fixed::setRawBits(int const raw)
{
	announce("setRawBits member function", "void   Fixed::setRawBits(int const raw)");

	this->numberValue = raw;
}
