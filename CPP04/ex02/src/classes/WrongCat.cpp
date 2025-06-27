#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default Constructor\n";
}

WrongCat::WrongCat(WrongCat const &original) : WrongAnimal(original)
{
	std::cout << "WrongCat Copy Constructor\n";
	*this = original;
}

WrongCat &WrongCat::operator=(WrongCat const &original)
{
	std::cout << "WrongCat Assignment Operator\n";
	if (this != &original)
	{
		WrongAnimal::operator=(original);
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor\n";
}
