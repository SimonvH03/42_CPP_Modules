#include "Harl.hpp"
#include <iostream>

#ifndef EINVAL
# define EINVAL 22
#endif

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: " << argv[0] << " <LEVEL(DEBUG:INFO:WARNING:ERROR)>\n";
		return (EINVAL);
	}

	switch (Harl::getLevelIndex(argv[1]))
	{
		default:
		{
			std::cout << "harl is confused and unfamiliar with this LEVEL of commentary\n";
			return (EINVAL);
		}
		case 0:
			Harl::complain(Harl::_levels[0]);
			// fallsthrough
		case 1:
			Harl::complain(Harl::_levels[1]);
			// fall through
		case 2:
			Harl::complain(Harl::_levels[2]);
			// fall through
		case 3:
			Harl::complain(Harl::_levels[3]);
			// fall through
	}
	return (0);
}
