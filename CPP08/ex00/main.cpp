#include <iostream>
#include <vector>

#include "easyfind.hpp"

static constexpr std::size_t Size = 100;

int main(void)
{
	const int			needle = 42;
	std::vector<int>	numbers(Size, 0);

	std::srand(time(NULL));
	for (size_t i = 0; i < Size; ++i)
		numbers[i] = std::rand();
	numbers.push_back(needle);
	if (*easyfind(numbers, needle) == needle)
		std::cout << "That was easy!\n";
	return 0;
}
