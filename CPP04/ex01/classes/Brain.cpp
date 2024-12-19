#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor\n";
	levelOfThought = 0;
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
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor\n";
}

void	Brain::inspire(std::string inspiration)
{
	ideas[levelOfThought] = inspiration;
	levelOfThought++;
}

void	Brain::inception(Brain *dest) const
{
	std::copy(ideas, ideas + 100, (*dest).ideas);
}
