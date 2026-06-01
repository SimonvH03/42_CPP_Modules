#include <iostream>
#include <random>

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <number of elements>\n";
		return (EINVAL);
	}

	unsigned int n = 0;

	try {
		n = std::stoi(argv[1]);
	} catch (std::invalid_argument &e) {
		std::cerr << "Error\nInvalid Argument: " << argv[1] << "\n";
		std::cout << "Error\n";
		return (EINVAL);
	}

	std::random_device	device;
	std::mt19937		twister(device());
	std::uniform_int_distribution<std::mt19937::result_type>	rand(1, std::pow(10, 5));

	for (unsigned int i = 0; i < n; i++) {
		std::cout << (rand(twister)) << " ";
	}
	std::cout << "\n";

	return (0);
}
