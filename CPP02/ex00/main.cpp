#include "Fixed.hpp"
# include <iostream>

int main(void)
{
	std::cout << "A simple demonstration of various ways to Construct object of the same Class 'Fixed'\n"
		<< "  The Default constructor sets Fixed.numberValue = 0\n"
		<< "  Fixed::getRawBits returns Fixed.numberValue\n"
		<< "  Fixed::operator=(&src) overloads usage of '=' operator on objects of the Fixed Class,\n"
		<< "    Sets numberValue = src.numberValue and returns (*this) as reference to this\n";
	std::cout << "\nCASE 1:\n1. object a is constructed by the Default Constructor: a.numberValue = 0 by default, \n"
		<< "2. object b is a copy of a, constructed by the Copy Constructor: b = a:\n    Operator= is overloaded: b.numberValue = a.numberValue\n"
		<< "Code:\n{\n\tFixed a; \e[2m\e[2m//Default Constructor\e[0m\n\tFixed b( a ); \e[2m//Copy Constructor -> operator=() -> getRawBits()\e[0m\n\tFixed c; \e[2m//Default Constructor\e[0m\n\tc = b; \e[2m//operator=() -> getRawBits()\e[0m\n\tstd::cout << a.getRawBits() << std::endl;\n\tstd::cout << b.getRawBits() << std::endl;\n\tstd::cout << c.getRawBits() << std::endl;\n}\nOutput:\n\n";
	{
		Fixed a;
		Fixed b( a );
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << "\nCASE 2:\nObject a is constructed and its numberValue changed before other objects\n  (partially to demonstrate setRawBits() works as expected)\n"
		<< "Code:\n{\n\tFixed a;\n\ta.setRawBits(42);\n\tFixed b( a );\n\tFixed c;\n\tc = b;\n\tstd::cout << a.getRawBits() << std::endl;\n\tstd::cout << b.getRawBits() << std::endl;\n\tstd::cout << c.getRawBits() << std::endl;\n}\nOutput:\n\n";
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
	std::cout << "\nCASE 3:\n1. object a is constructed and its numberValue changed after object copies b and c are Constructed\n"
		<< "    This shows changing the value of an object does not change the value of its copy\n"
		<< "2. object b is changed after confirming changing a did not affect b or c,\n"
		<< "    confirming the copy method used to make c from b is of the same independent nature\n"
		<< "Code:\n{\n\tFixed a;\n\tFixed b( a );\n\ta.setRawBits(42);\n\tFixed c;\n\tc = b;\n\tstd::cout << a.getRawBits() << std::endl;\n\tstd::cout << b.getRawBits() << std::endl;\n\tstd::cout << c.getRawBits() << std::endl;\n\tb.setRawBits(42);\n\tstd::cout << b.getRawBits() << std::endl;\n\tstd::cout << c.getRawBits() << std::endl;\n}\nOutput:\n\n";
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
	std::cout << "\nCASE 4:\nObject a is constructed, object b and c are constructed as copies of object a, then both object b and c are changed\n"
		<< "    This shows changing the value of any copied object does not change the value of any other,\n"
		<< "        they are independent in both 'directions', as expected\n"
		<< "Code:\n{\n\tFixed a;\n\tFixed b( a );\n\tFixed c;\n\tc = b;\n\ta.setRawBits(42);\n\tb.setRawBits(7);\n\tc.setRawBits(-1);\n\tstd::cout << a.getRawBits() << std::endl;\n\tstd::cout << b.getRawBits() << std::endl;\n\tstd::cout << c.getRawBits() << std::endl;\n}\nOutput:\n\n";
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
