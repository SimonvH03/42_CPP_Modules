#include "Fixed.hpp"

void	Fixed::announce(std::string const &name, std::string const &func)
const
{
	std::cout << "called:\t" << std::setw(27) << name
		<< "\e[2m\t" << func << "\e[0m\n";
}

Fixed::Fixed()
{
	announce("Default Constructor", "Fixed::Fixed()");

	setRawBits(0);
}

Fixed::Fixed(int const iValue)
{
	announce("Int Constructor", "Fixed::Fixed(int const iValue)");

	setRawBits(iValue);
}

Fixed::Fixed(float const fValue)
{
	announce("Float Constructor", "Fixed::Fixed(float const fValue)");

	setRawBits(fValue);
}

Fixed::Fixed(Fixed const &src)
{
	announce("Copy Constructor", "Fixed::Fixed(Fixed const &src)");

	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	announce("Copy assignment operator", "Fixed  &Fixed::operator=(Fixed const &src)");

	if (this != &src)
	{
		raw = src.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	announce("Destructor", "Fixed::~Fixed()");
}

int		Fixed::toInt(void)
const
{
	return (raw >> fractionalBits);
}

float	Fixed::toFloat(void)
const
{
	return (raw / (float)(1 << fractionalBits));
}

void	Fixed::setRawBits(int const asInt)
{
	announce("setRawBits member function", "void   Fixed::setRawBits(int const asInt)");

	raw = asInt << fractionalBits;
	// std::cout << "Set raw raw: " << raw << " (" << asInt << ")\n";
}

void	Fixed::setRawBits(float const asFloat)
{
	announce("setRawBits member function", "void   Fixed::setRawBits(float const asFloat)");

	raw = asFloat * (1 << fractionalBits);
	// std::cout << "Set raw raw: " << raw << " (" << asFloat << ")\n";
}

int		Fixed::getRawBits()
const
{
	announce("getRawBits member function", "int    Fixed::getRawBits() const");

	return (raw);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}
