#include "TestCase.hpp"

TestCase::TestCase(std::string const &testName)
	:	_name(testName)
{
#ifdef VERBOSE
	std::cout << "TestCase Name Constructor: " << _name << "\n";
#endif
}

TestCase::~TestCase()
{
#ifdef VERBOSE
	std::cout << "TestCase Destructor\n";
#endif
}

std::string const	&TestCase::getName() const
{
	return (_name);
}
