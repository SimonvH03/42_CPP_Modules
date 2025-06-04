#include "UnitTest.hpp"

UnitTest::UnitTest()
{}

UnitTest::UnitTest(UnitTest const &original)
{
	*this = original;
}

UnitTest &UnitTest::operator=(UnitTest const &original)
{
	if (this != &original)
	{
	}
	return (*this);
}

UnitTest::~UnitTest()
{}

const char *UnitTest::TestAssertionError::what() const throw()
{
	return ("Assertion failed");
}
