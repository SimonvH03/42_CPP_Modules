#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor\n";
	knowledge = 0;
	thoughts_had = 0;
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
		knowledge = original.knowledge;
		thoughts_had = original.thoughts_had;
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
	while (knowledge < BRAIN_CAPACITY && std::getline(file, line))
	{
		ideas[knowledge] = line;
		knowledge++;
	}
}

void	Brain::think()
{
	if (thoughts_had > knowledge)
		thoughts_had = 0;
	std::cout << "thought " << thoughts_had << ": " << ideas[thoughts_had] << '\n';
	thoughts_had++;
}
