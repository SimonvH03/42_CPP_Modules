#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default Constructor\n";
	type = "Harl???";
}

WrongAnimal::WrongAnimal(WrongAnimal const &original)
{
	std::cout << "WrongAnimal Copy Constructor\n";
	*this = original;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &original)
{
	std::cout << "WrongAnimal Assignment Operator\n";
	if (this != &original)
	{
		type = original.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor\n";
}

void	WrongAnimal::makeSound()
const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

std::string	WrongAnimal::getType()
const
{
	return (type);
}
