#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor\n";
}

MateriaSource::MateriaSource(MateriaSource const &original)
{
	std::cout << "MateriaSource Copy Constructor\n";
	*this = original;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &original)
{
	std::cout << "MateriaSource Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor\n";
}
