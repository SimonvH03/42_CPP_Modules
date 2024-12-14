#include "Fixed.hpp"

Fixed::Fixed()
{
	announce("Default Constructor", "Fixed::Fixed()");

	this->setRawBits(0);
}

Fixed::Fixed(int const iValue)
{
	announce("Int Constructor", "Fixed::Fixed()");

	this->setRawBits(iValue);
}

Fixed::Fixed(float const fValue)
{
	announce("Float Constructor", "Fixed::Fixed()");

	this->setRawBits(fValue);
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
		this->setRawBits(src.getRawBits());
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

	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	announce("setRawBits member function", "void   Fixed::setRawBits(int const raw)");

	this->value = raw;
}

float	Fixed::toFloat() const
{
	return (1);
}

int	Fixed::toInt() const
{
	return (1);
}
