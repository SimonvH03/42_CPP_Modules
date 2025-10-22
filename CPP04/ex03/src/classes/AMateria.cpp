#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Default Constructor\n";
}

AMateria::AMateria(std::string const &_type) : type(_type)
{
	std::cout << "AMateria Constructor(type)\n";
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
		type = original.type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor\n";
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "AMysterious Material is flung towards " << target.getName() << "\n";
}

std::string const	&AMateria::getType()
const
{
	return (type);
}
