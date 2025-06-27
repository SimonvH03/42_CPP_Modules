#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor\n";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(Cat const &original) : Animal(original)
{
	std::cout << "Cat Copy Constructor\n";
	brain = new Brain();
	*this = original;
}

Cat &Cat::operator=(Cat const &original)
{
	std::cout << "Cat Assignment Operator\n";
	if (this != &original)
	{
		Animal::operator=(original);
		delete brain;
		brain = new Brain(*original.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor\n";
	delete brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow\n";
	brain->think();
}
