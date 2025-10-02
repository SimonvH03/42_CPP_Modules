#include <iostream>

#include "Array.hpp"

namespace Config
{
	constexpr unsigned int	Size = 750;
}

int	main(void)
{
	// Array<int>	numbers(Config::Size);
	Array<size_t>	numbers(Config::Size);
	// int			*mirror = new int[Config::Size];
	size_t		*mirror = new size_t[Config::Size];

	srand(time(NULL));
	for (size_t i = 0; i < Config::Size; i++)
	{
		const size_t value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	{
		// Array<int> tmp;
		Array<size_t> tmp;
		tmp = numbers;
		// Array<int> test(tmp);
		Array<size_t> test(tmp);
		for (size_t i = 0; i < Config::Size; i++)
		{
			if (mirror[i] != numbers[i]
				|| tmp[i] != numbers[i]
				|| test[i] != numbers[i])
			{
				std::cerr << "Value incorrectly assigned / copied: "
					<< numbers[i] << ", arr[n] = value: "
					<< mirror[i] << ", arr = original: "
					<< tmp[i] << ", arr(original): "
					<< test [i] << std::endl;
				break ;
			}
		}
	}

	try {
		numbers[-2] = 0;
	} catch(std::exception const &except) {
		std::cerr << "exception caught in main(): " << except.what() << '\n';
	}
	try {
		numbers[Config::Size] = 0;
	} catch(std::exception const &except) {
		std::cerr << "exception caught in main(): " << except.what() << '\n';
	}
	for (size_t i = 0; i < Config::Size; i++)
	{
		numbers[i] = rand();
	}

	delete [] mirror;
	return 0;
}
