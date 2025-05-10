#include "Fixed.hpp"

void	Fixed::announce(std::string const &name, std::string const &func) const
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

bool	Fixed::operator>(Fixed const &num) const
{
	return (raw > num.raw);
}

bool	Fixed::operator<(Fixed const &num) const
{
	return (raw < num.raw);
}

bool	Fixed::operator>=(Fixed const &num) const
{
	return (raw >= num.raw);
}

bool	Fixed::operator<=(Fixed const &num) const
{
	return (raw <= num.raw);
}

bool	Fixed::operator==(Fixed const &num) const
{
	return (raw == num.raw);
}

bool	Fixed::operator!=(Fixed const &num) const
{
	return (raw != num.raw);
}

Fixed	Fixed::operator+(Fixed const &num) const
{
	Fixed	result(*this);
	result.raw += num.raw;
	return (result);
}

Fixed	Fixed::operator-(Fixed const &num) const
{
	Fixed	result(*this);
	result.raw -= num.raw;
	return (result);
}

Fixed	Fixed::operator*(Fixed const &num) const
{
	Fixed	result;
	result.raw = (int64_t)raw * num.raw >> fractionalBits;
	return (result);
}

Fixed	Fixed::operator/(Fixed const &num) const
{
	Fixed	result;
	result.raw = (int64_t)(raw << fractionalBits) / num.raw;
	return (result);
}

Fixed&	Fixed::operator+=(Fixed const &num)
{
	*this = (*this + num);
	return (*this);
}

Fixed&	Fixed::operator-=(Fixed const &num)
{
	*this = (*this - num);
	return (*this);
}

Fixed&	Fixed::operator*=(Fixed const &num)
{
	*this = (*this * num);
	return (*this);
}

Fixed&	Fixed::operator/=(Fixed const &num)
{
	*this = (*this / num);
	return (*this);
}

Fixed&	Fixed::operator++()
{
	++raw;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	--raw;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++raw;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--raw;
	return (temp);
}

int		Fixed::toInt(void) const
{
	return (raw >> fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return (raw / (float)(1 << fractionalBits));
}

void	Fixed::setRawBits(int const asInt)
{
	raw = asInt << fractionalBits;
}

void	Fixed::setRawBits(float const asFloat)
{
	raw = asFloat * (1 << fractionalBits);
}

int		Fixed::getRawBits() const
{
	return (raw);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed const&	Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
}

Fixed const&	Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
}

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}
