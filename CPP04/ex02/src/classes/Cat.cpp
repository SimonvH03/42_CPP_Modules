#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor\n";
	type = "Cat";
	brain = new Brain();
	levelOfThought = 0;
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
		delete brain;
		brain = new Brain();
		brain = original.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor\n";
	delete brain;
}

void	Cat::makeSound()
{
	std::cout << "Meow\n";
	think();
}

void	Cat::think()
{
	std::cout << "thought " << levelOfThought << ": " << brain->ideas[levelOfThought] << '\n';
	levelOfThought++;
}
