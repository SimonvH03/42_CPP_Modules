#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	std::cout << "IMateriaSource Default Constructor\n";
}

IMateriaSource::IMateriaSource(IMateriaSource const &original)
{
	std::cout << "IMateriaSource Copy Constructor\n";
	*this = original;
}

IMateriaSource &IMateriaSource::operator=(IMateriaSource const &original)
{
	std::cout << "IMateriaSource Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

IMateriaSource::~IMateriaSource()
{
	std::cout << "IMateriaSource Destructor\n";
}
