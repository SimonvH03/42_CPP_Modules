#include "Fixed.hpp"

Fixed::Fixed()
	:	raw(0)
{
#ifdef VERBOSE
	std::cout << "Fixed Default Constructor\n";
#endif
}

Fixed::Fixed(Fixed const &src)
	:	raw(src.raw)
{
#ifdef VERBOSE
	std::cout << "Fixed Copy Constructor\n";
#endif
}

Fixed::Fixed(int const asInt)
	:	raw(0)
{
#ifdef VERBOSE
	std::cout << "Fixed Int Constructor\n";
#endif

	setRawBits(asInt);
}

Fixed::Fixed(float const asFloat)
	:	raw(0)
{
#ifdef VERBOSE
	std::cout << "Fixed Float Constructor\n";
#endif

	setRawBits(asFloat);
}

Fixed	&Fixed::operator=(Fixed const &src)
{
#ifdef VERBOSE
	std::cout << "Fixed Assignment Operator\n";
#endif

	if (this != &src)
	{
		raw = src.raw;
	}
	return (*this);
}

Fixed::~Fixed()
{
#ifdef VERBOSE
	std::cout << "Fixed Destructor\n";
#endif
}

void	Fixed::setRawBits(int const asInt)
{
#ifdef VERBOSE
	std::cout << "Fixed setRawBits(int)\n";
#endif

	raw = asInt << fractionalBits;
}

void	Fixed::setRawBits(float const asFloat)
{
#ifdef VERBOSE
	std::cout << "Fixed setRawBits(float)\n";
#endif

	raw = asFloat * (1 << fractionalBits);
}

int	Fixed::getRawBits()
const
{
	return (raw);
}

int		Fixed::toInt(void)
const
{
	return (raw >> fractionalBits);
}

float	Fixed::toFloat(void)
const
{
	return (raw / static_cast<float>(1 << fractionalBits));
}

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}
