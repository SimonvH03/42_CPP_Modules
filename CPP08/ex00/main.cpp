#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(void)
{
	const int			needle = 42;
	std::vector<int>	haystack(999, 0);

	std::srand(time(NULL));
	std::generate(haystack.begin(), haystack.end(), std::rand);
	haystack.push_back(needle);

	std::vector<int>::iterator	found = easyfind(haystack, needle);
	*(found - 1) = 43;
	if (*found == needle)
		std::cout << "That was easy!\n";
	return 0;
}
