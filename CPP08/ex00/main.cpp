#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(void)
{
	const int			needle = 42;
	std::vector<int>	haystack(999, 0);
	const int			testIterations = 42;
	unsigned int		passed = 0;
	unsigned int		ran = 0;

	std::srand(time(NULL));

	while (ran < testIterations)
	{
		std::generate(haystack.begin(), haystack.end(), std::rand);
		haystack.push_back(needle);

		std::vector<int>::iterator	found = easyfind(haystack, needle);

		*(found - 1) = 43; // real modifiable iterator?
		if (*found == needle)
			++passed;
		++ran;
	}
	std::cout << ((passed == ran) ? "\e[32m" : "\e[32m") << passed << "/" << ran << "\e[0m iterations passed.\n"
		<< ((passed == ran) ? "Easy peasy lemon squeezy\n" : "Difficult difficult lemon difficult\n");
	return 0;
}
