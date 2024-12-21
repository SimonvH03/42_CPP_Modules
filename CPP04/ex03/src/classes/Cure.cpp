#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure Default Constructor\n";
	type = "cure";
}

Cure::Cure(Cure const &original) : AMateria::AMateria(original)
{
	std::cout << "Cure Copy Constructor\n";
	*this = original;
}

Cure &Cure::operator=(Cure const &original)
{
	std::cout << "Cure Assignment Operator\n";
	if (this != &original)
	{
		// Subject said it doesn't make sense... ok
		// AMateria::operator=(original);
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor\n";
}

AMateria *
Cure::clone()
const
{
	AMateria	*clone = new Cure();

	*clone = *this;
	return (clone);
}

void
Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
