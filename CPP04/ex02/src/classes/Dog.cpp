#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constructor\n";
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(Dog const &original) : Animal(original), brain(NULL)
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
		delete brain;
		brain = new Brain(*original.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor\n";
	delete brain;
}

void	Dog::makeSound() const
{
	std::cout << "Bark\n";
	brain->think();
}
