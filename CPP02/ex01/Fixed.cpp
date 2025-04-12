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

	setRawBits(0);
}

Fixed::Fixed(int const iValue)
{
	announce("Int Constructor", "Fixed::Fixed()");

	setRawBits(iValue);
}

Fixed::Fixed(float const fValue)
{
	announce("Float Constructor", "Fixed::Fixed()");

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
		value = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	announce("Destructor", "Fixed::~Fixed()");
}

int		Fixed::getRawBits() const
{
	announce("getRawBits member function", "int    Fixed::getRawBits() const");

	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	announce("setRawBits member function", "void   Fixed::setRawBits(int const raw)");

	value = raw << Fixed::bitCount;
	// std::cout << "Set iValue: " << value << '\n';
}

void	Fixed::setRawBits(float const raw)
{
	announce("setRawBits member function", "void   Fixed::setRawBits(float const raw)");

	// value = raw * (1 << Fixed::bitCount);
	value = round(raw * (1 << Fixed::bitCount));
	// std::cout << "Set fValue: " << value << '\n';
}

int		Fixed::toInt(void) const
{
	// return (value >> Fixed::bitCount);
	return round(value >> Fixed::bitCount);
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(value) / ( 1 << Fixed::bitCount);
}
