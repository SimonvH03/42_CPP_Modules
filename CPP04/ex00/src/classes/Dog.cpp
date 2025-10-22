#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constructor\n";
	type = "Dog";
}

Dog::Dog(Dog const &original) : Animal(original)
{
	std::cout << "Dog Copy Constructor\n";
	*this = original;
}

Dog &Dog::operator=(Dog const &original)
{
	std::cout << "Dog Assignment Operator\n";
	if (this != &original)
	{
		Animal::operator=(original);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor\n";
}

void	Dog::makeSound()
const
{
	std::cout << "Bark\n";
}
