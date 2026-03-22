#include <iostream>
#include <span>

#include "classes/RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " \"<digit> 1*<operation digit>\"\n";
		return (EINVAL);
	}

	try {
		std::cout << ReversePolishNotation::calc(std::istringstream(argv[1])) << "\n";
	} catch (std::runtime_error const &e) {
		std::cerr << "Error: " << e.what() << "\n";
	} catch (std::logic_error const &e) {
		std::cerr << "Error: Code invalid: " << e.what() << "\n";
	}

	return (0);
}
