#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure Default Constructor\n";
}

Cure::Cure(Cure const &original)
{
	std::cout << "Cure Copy Constructor\n";
	*this = original;
}

Cure &Cure::operator=(Cure const &original)
{
	std::cout << "Cure Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor\n";
}
