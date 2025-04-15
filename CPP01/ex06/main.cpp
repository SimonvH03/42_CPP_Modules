#include "Harl.hpp"
#include <iostream>

#ifndef EINVAL
# define EINVAL 22
#endif

int main(int argc, char **argv)
{
	Harl		harl;
	std::string input;

	if (argc != 2)
	{
		std::cout << "usage: ./harlFilter <LEVEL(DEBUG:INFO:WARNING:ERROR)>\n";
		return (EINVAL);
	}
	switch (harl.getLevel(argv[1]))
	{
		default:
		{
			std::cout << "harl is confused and unfamiliar with this LEVEL of commentary\n";
			return (EINVAL);
		}
		case 0:
			harl.complain(harl._levels[0]);
			// fall through
		case 1:
			harl.complain(harl._levels[1]);
			// fall through
		case 2:
			harl.complain(harl._levels[2]);
			// fall through
		case 3:
			harl.complain(harl._levels[3]);
			// fall through
	}
	return (0);
}
