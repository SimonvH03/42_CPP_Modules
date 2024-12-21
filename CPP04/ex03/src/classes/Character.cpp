#include "Character.hpp"

Character::Character()
{
	std::cout << "Character Default Constructor\n";
}

Character::Character(Character const &original)
{
	std::cout << "Character Copy Constructor\n";
	*this = original;
}

Character &Character::operator=(Character const &original)
{
	std::cout << "Character Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character Destructor\n";
}
