#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constructor\n";
	type = "Dog";
	brain = new Brain();
	levelOfThought = 0;
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
		delete brain;
		brain = new Brain();
		original.brain->inception(brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor\n";
	delete brain;
}

void	Dog::makeSound()
{
	std::cout << "Bark\n";
	think();
}

void	Dog::think()
{
	std::cout << "thought " << levelOfThought << ":\n";
	std::cout << brain->ideas[levelOfThought] << '\n';
	levelOfThought++;
}