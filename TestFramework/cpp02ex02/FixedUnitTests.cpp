#include "Fixed.hpp"
#include "UnitTest.hpp"

void	assert(bool evaluation)
{
	if (evaluation == false)
		throw 
}

bool	operator>UnitTest(Fixed const &num) const
{
	return (raw > num.raw);
}

bool	operator<UnitTest(Fixed const &num) const
{
	return (raw < num.raw);
}

bool	operator>=UnitTest(Fixed const &num) const
{
	return (raw >= num.raw);
}

bool	operator<=UnitTest(Fixed const &num) const
{
	return (raw <= num.raw);
}

bool	operator==UnitTest(Fixed const &num) const
{
	return (raw == num.raw);
}

bool	operator!=UnitTest(Fixed const &num) const
{
	return (raw != num.raw);
}

Fixed	operator+UnitTest(Fixed const &num) const
{
	Fixed	result(*this);
	result.raw += num.raw;
	return (result);
}

Fixed	operator-UnitTest(Fixed const &num) const
{
	Fixed	result(*this);
	result.raw -= num.raw;
	return (result);
}

Fixed	operator*UnitTest(Fixed const &num) const
{
	Fixed	result;
	result.raw = (int64_t)raw * num.raw >> fractionalBits;
	return (result);
}

Fixed	operator/UnitTest(Fixed const &num) const
{
	Fixed	result;
	result.raw = (int64_t)(raw << fractionalBits) / num.raw;
	return (result);
}

Fixed&	operator+=UnitTest(Fixed const &num)
{
	*this = (*this + num);
	return (*this);
}

Fixed&	operator-=UnitTest(Fixed const &num)
{
	*this = (*this - num);
	return (*this);
}

Fixed&	operator*=UnitTest(Fixed const &num)
{
	*this = (*this * num);
	return (*this);
}

Fixed&	operator/=UnitTest(Fixed const &num)
{
	*this = (*this / num);
	return (*this);
}

Fixed&	operator++UnitTest()
{
	++raw;
	return (*this);
}

Fixed&	operator--UnitTest()
{
	--raw;
	return (*this);
}

Fixed	operator++UnitTest(int)
{
	Fixed temp = *this;
	++raw;
	return (temp);
}

Fixed	operator--UnitTest(int)
{
	Fixed temp = *this;
	--raw;
	return (temp);
}

int		toIntUnitTest(void) const
{
	return (raw >> fractionalBits);
}

float	toFloatUnitTest(void) const
{
	return (raw / (float)(1 << fractionalBits));
}

void	setRawBitsUnitTest(int const asInt)
{
	raw = asInt << fractionalBits;
}

void	setRawBitsUnitTest(float const asFloat)
{
	raw = asFloat * (1 << fractionalBits);
}

int		getRawBitsUnitTest() const
{
	return (raw);
}

Fixed&	minUnitTest(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed&	maxUnitTest(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed const&	minUnitTest()
{
	Fixed a(0);
	Fixed b(0);

	assert
}

Fixed const&	maxUnitTest()
{

}
