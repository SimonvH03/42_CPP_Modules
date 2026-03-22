#include <iostream>

#include "classes/BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input.csv>\n";
		return (EINVAL);
	}

	try {
		BitcoinExchange	dataBase;
		dataBase.report(argv[1]);
	} catch (std::exception const &e) {
		std::cerr << "Error: " << e.what() << "\n";
		return (1);
	}

	return (0);
}
