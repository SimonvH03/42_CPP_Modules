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

bool	Fixed::operator>(Fixed const &num)
const
{
#ifdef VERBOSE
	std::cout << "Fixed > Operator\n";
#endif

	return (raw > num.raw);
}

bool	Fixed::operator<(Fixed const &num)
const
{
#ifdef VERBOSE
	std::cout << "Fixed < Operator\n";
#endif

	return (raw < num.raw);
}

bool	Fixed::operator>=(Fixed const &num)
const
{
#ifdef VERBOSE
	std::cout << "Fixed >= Operator\n";
#endif

	return (raw >= num.raw);
}

bool	Fixed::operator<=(Fixed const &num)
const
{
#ifdef VERBOSE
	std::cout << "Fixed <= Operator\n";
#endif

	return (raw <= num.raw);
}

bool	Fixed::operator==(Fixed const &num)
const
{
#ifdef VERBOSE
	std::cout << "Fixed == Operator\n";
#endif

	return (raw == num.raw);
}

bool	Fixed::operator!=(Fixed const &num)
const
{
#ifdef VERBOSE
	std::cout << "Fixed != Operator\n";
#endif

	return (raw != num.raw);
}

Fixed	Fixed::operator+(Fixed const &num)
const
{
#ifdef VERBOSE
	std::cout << "Fixed + Operator\n";
#endif

	Fixed	result(*this);
	result.raw += num.raw;
	return (result);
}

Fixed	Fixed::operator-(Fixed const &num)
const
{
#ifdef VERBOSE
	std::cout << "Fixed - Operator\n";
#endif

	Fixed	result(*this);
	result.raw -= num.raw;
	return (result);
}

Fixed	Fixed::operator*(Fixed const &num)
const
{
#ifdef VERBOSE
	std::cout << "Fixed * Operator\n";
#endif

	Fixed	result;
	result.raw = (int64_t)raw * num.raw >> fractionalBits;
	return (result);
}

Fixed	Fixed::operator/(Fixed const &num)
const
{
#ifdef VERBOSE
	std::cout << "Fixed / Operator\n";
#endif

	Fixed	result;
	result.raw = (int64_t)(raw << fractionalBits) / num.raw;
	return (result);
}

Fixed&	Fixed::operator+=(Fixed const &num)
{
#ifdef VERBOSE
	std::cout << "Fixed += Operator\n";
#endif

	*this = (*this + num);
	return (*this);
}

Fixed&	Fixed::operator-=(Fixed const &num)
{
#ifdef VERBOSE
	std::cout << "Fixed -= Operator\n";
#endif

	*this = (*this - num);
	return (*this);
}

Fixed&	Fixed::operator*=(Fixed const &num)
{
#ifdef VERBOSE
	std::cout << "Fixed *= Operator\n";
#endif

	*this = (*this * num);
	return (*this);
}

Fixed&	Fixed::operator/=(Fixed const &num)
{
#ifdef VERBOSE
	std::cout << "Fixed /= Operator\n";
#endif

	*this = (*this / num);
	return (*this);
}

Fixed&	Fixed::operator++()
{
#ifdef VERBOSE
	std::cout << "Fixed ++ Operator\n";
#endif

	++raw;
	return (*this);
}

Fixed&	Fixed::operator--()
{
#ifdef VERBOSE
	std::cout << "Fixed -- Operator\n";
#endif

	--raw;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
#ifdef VERBOSE
	std::cout << "Fixed ++(int) Operator\n";
#endif

	Fixed temp = *this;
	++raw;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
#ifdef VERBOSE
	std::cout << "Fixed --(int) Operator\n";
#endif

	Fixed temp = *this;
	--raw;
	return (temp);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
#ifdef VERBOSE
	std::cout << "Fixed min()\n";
#endif

	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
#ifdef VERBOSE
	std::cout << "Fixed max()\n";
#endif

	return ((a > b) ? a : b);
}

Fixed const&	Fixed::min(Fixed const &a, Fixed const &b)
{
#ifdef VERBOSE
	std::cout << "Fixed min()\n";
#endif

	return ((a < b) ? a : b);
}

Fixed const&	Fixed::max(Fixed const &a, Fixed const &b)
{
#ifdef VERBOSE
	std::cout << "Fixed max()\n";
#endif

	return ((a > b) ? a : b);
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
