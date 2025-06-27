#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal Default Constructor\n";
}

Animal::Animal(Animal const &original)
{
	std::cout << "Animal Copy Constructor\n";
	*this = original;
}

Animal &Animal::operator=(Animal const &original)
{
	std::cout << "Animal Assignment Operator\n";
	if (this != &original)
	{
		type = original.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor\n";
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout <<  "I'm an Animal, I swear!\n";
}
