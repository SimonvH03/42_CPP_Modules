#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice Default Constructor\n";
}

Ice::Ice(Ice const &original)
{
	std::cout << "Ice Copy Constructor\n";
	*this = original;
}

Ice &Ice::operator=(Ice const &original)
{
	std::cout << "Ice Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Destructor\n";
}
