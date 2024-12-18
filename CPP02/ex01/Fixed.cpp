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
		this->value = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	announce("Destructor", "Fixed::~Fixed()");
}

int		Fixed::getRawBits() const
{
	announce("getRawBits member function", "int    Fixed::getRawBits() const");

	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	announce("setRawBits member function", "void   Fixed::setRawBits(int const raw)");

	this->value = raw << Fixed::bitCount;
	// std::cout << "Set iValue: " << this->value << '\n';
}

void	Fixed::setRawBits(float const raw)
{
	announce("setRawBits member function", "void   Fixed::setRawBits(float const raw)");

	// this->value = raw * (1 << Fixed::bitCount);
	this->value = round(raw * (1 << Fixed::bitCount));
	// std::cout << "Set fValue: " << this->value << '\n';
}

int		Fixed::toInt(void) const
{
	// return (this->value >> Fixed::bitCount);
	return round(this->value >> Fixed::bitCount);
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(this->value) / ( 1 << Fixed::bitCount);
}
