#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor\n";
	type = "Cat";
}

Cat::Cat(Cat const &original) : Animal(original)
{
	std::cout << "Cat Copy Constructor\n";
	*this = original;
}

Cat &Cat::operator=(Cat const &original)
{
	std::cout << "Cat Assignment Operator\n";
	if (this != &original)
	{
		Animal::operator=(original);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor\n";
}

void	Cat::makeSound()
const
{
	std::cout << "Meow\n";
}