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
		std::copy(original.ideas, original.ideas + 100, ideas);
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor\n";
}

void	Brain::fileStudy(std::string fileName)
{
	int		fd = open(fileName.c_str(), O_RDONLY);
	char	*line;

	if (fd == -1)
	{
		std::cout << "failed to open file " << fileName.c_str() << " for study\n";
		return ;
	}
	while (intelligence < BRAIN_CAPACITY)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ideas[intelligence] = line;
		free(line);
		intelligence++;
	}
	get_next_line(-1);
	close(fd);
}
