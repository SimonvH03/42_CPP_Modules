#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	std::cout << "A simple demonstration of various ways to Construct object of the same Class 'Fixed'\n"
		<< "  The Default constructor sets Fixed.raw = 0\n"
		<< "  Fixed::getRawBits returns Fixed.raw\n"
		<< "  Fixed::operator=(&src) overloads usage of '=' operator on objects of the Fixed Class,\n"
		<< "    Sets raw = src.raw and returns (*this) as reference to this\n";
	std::cout << "\n\e[1;3mCASE 1:\n1. object a is constructed by the Default Constructor: a.raw = 0 by default, \n"
		<< "2. object b is a copy of a, constructed by the Copy Constructor: b = a:\n"
		<< "    Operator= is overloaded: b.raw = a.raw\n\n\e[0m";
	{
		Fixed a;
		Fixed b( a );
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << "\n\e[1;3mCASE 2:\nObject a is constructed and its raw changed before other objects\n"
		<< "    (partially to demonstrate setRawBits() works as expected)\n\n\e[0m";
	{
		Fixed a;
		a.setRawBits(42);
		Fixed b( a );
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << "\n\e[1;3mCASE 3:\n1. object a is constructed and its raw changed after object copies b and c are Constructed\n"
		<< "    This shows changing the value of an object does not change the value of its copy\n"
		<< "2. object b is changed after confirming changing a did not affect b or c,\n"
		<< "    confirming the copy method used to make c from b is of the same independent nature\n\n\e[0m";
	{
		Fixed a;
		Fixed b( a );
		a.setRawBits(42);
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
		b.setRawBits(42);
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << "\n\e[1;3mCASE 4:\nObject a is constructed, object b and c are constructed as copies of object a, then both object b and c are changed\n"
		<< "    This shows changing the value of any copied object does not change the value of any other,\n"
		<< "        they are independent in both 'directions', as expected\n\n\e[0m";
	{
		Fixed a;
		Fixed b( a );
		Fixed c;
		c = b;
		a.setRawBits(42);
		b.setRawBits(7);
		c.setRawBits(-1);
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	return 0;
}
