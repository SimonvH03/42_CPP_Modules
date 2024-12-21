#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Default Constructor\n";
}

AMateria::AMateria(AMateria const &original)
{
	std::cout << "AMateria Copy Constructor\n";
	*this = original;
}

AMateria &AMateria::operator=(AMateria const &original)
{
	std::cout << "AMateria Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor\n";
}
