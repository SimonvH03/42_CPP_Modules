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
	std::cout << "Fixed setRawBits()\n";
#endif

	raw = asInt;
}

int	Fixed::getRawBits()
const
{
	return (raw);
}
