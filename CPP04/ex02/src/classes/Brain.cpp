#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor\n";
	intelligence = 0;
	fileStudy("Lorem_Ipsum_350");
}

Brain::Brain(Brain const &original)
{
	std::cout << "Brain Copy Constructor\n";
	*this = original;
}

Brain &Brain::operator=(Brain const &original)
{
	std::cout << "Brain Assignment Operator\n";
	if (this != &original)
	{
		std::copy(original.ideas, original.ideas + BRAIN_CAPACITY, ideas);
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor\n";
}

void	Brain::fileStudy(std::string fileName)
{
	std::ifstream	file(fileName.c_str());
	std::string		line;

	if (!file)
	{
		std::cout << "failed to open file " << fileName << " for study\n";
		return ;
	}
	while (intelligence < BRAIN_CAPACITY && std::getline(file, line))
	{
		ideas[intelligence] = line;
		intelligence++;
	}
}
