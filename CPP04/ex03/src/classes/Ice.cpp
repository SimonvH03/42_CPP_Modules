#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice Default Constructor\n";
	type = "ice";
}

Ice::Ice(Ice const &original) : AMateria::AMateria(original)
{
	std::cout << "Ice Copy Constructor\n";
	*this = original;
}

Ice &Ice::operator=(Ice const &original)
{
	std::cout << "Ice Assignment Operator\n";
	if (this != &original)
	{
		// Subject said it doesn't make sense... ok
		// AMateria::operator=(original);
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Destructor\n";
}

AMateria	*Ice::clone() const
{
	AMateria	*clone = new Ice();

	*clone = *this;
	return (clone);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
