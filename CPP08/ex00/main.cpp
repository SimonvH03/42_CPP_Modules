#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(void)
{
	const size_t		N = 3;
	const int			needle = 42;
	std::vector<int>	numbers(N, 0);

	numbers.push_back(needle);
	if (*easyfind(numbers, needle) == needle)
		std::cout << "That was easy!\n";
	return 0;
}
