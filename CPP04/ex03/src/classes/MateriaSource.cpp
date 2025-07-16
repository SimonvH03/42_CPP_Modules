#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor\n";
	for (int i = 0; i < BOOK_CAPACITY; i++)
		typeBook[i] = NULL;
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
		for (int i = 0; i < BOOK_CAPACITY; i++)
		{
			if (typeBook[i])
				delete typeBook[i];
			if (original.typeBook[i])
				typeBook[i] = original.typeBook[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor\n";
	for (int i = 0; i < BOOK_CAPACITY; i++)
		if (typeBook[i])
			delete typeBook[i];
}

int	MateriaSource::getBookUsage() const
{
	int	IQ;
	
	IQ = 0;
	while (IQ < BOOK_CAPACITY && typeBook[IQ])
		IQ++;
	return (IQ);
}

void	MateriaSource::learnMateria(AMateria *subject)
{
	const int	i = getBookUsage();

	if (i == BOOK_CAPACITY)
		return ;
	typeBook[i] = subject->clone();
	std::cout << "MateriaSource learned all about a strange Materia of type " << subject->getType() << ", it can now create it\n";
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	const int	knowledge = getBookUsage();
	int			i = 0;
	
	while (i < knowledge)
	{
		if (type == typeBook[i]->getType())
			return (typeBook[i]->clone());
		i++;
	}
	std::cout << "MateriaSource is unfamiliar with Materia of type " << type << ", but is eager to learn it\n";
	return (NULL);
}
