#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "ICharacter Default Constructor\n";
}

ICharacter::ICharacter(ICharacter const &original)
{
	std::cout << "ICharacter Copy Constructor\n";
	*this = original;
}

ICharacter &ICharacter::operator=(ICharacter const &original)
{
	std::cout << "ICharacter Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

ICharacter::~ICharacter()
{
	std::cout << "ICharacter Destructor\n";
}
