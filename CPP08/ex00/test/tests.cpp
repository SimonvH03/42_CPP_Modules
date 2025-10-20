#include "TestCreation.hpp"
#include "ValidationTools.hpp"

#include "easyfind.hpp"

#include <vector>
#include <deque>

constexpr int	needle = 42;

TEST(vector) {
	std::vector<int>			haystack(999, 0);
	std::vector<int>::iterator	begin = haystack.begin();
	std::vector<int>::iterator	end = haystack.end();

	std::generate(begin, end, std::rand);
	haystack.insert((begin + std::distance(begin, end) / 2), needle);

	std::vector<int>::iterator	found = easyfind(haystack, needle);

	EQUATE(*found, needle);
}

TEST(deque) {
	std::deque<int>				haystack(999, 0);
	std::deque<int>::iterator	begin = haystack.begin();
	std::deque<int>::iterator	end = haystack.end();

	std::generate(begin, end, std::rand);
	haystack.insert((begin + std::distance(begin, end) / 2), needle);

	std::deque<int>::iterator	found = easyfind(haystack, needle);

	EQUATE(*found, needle);
}
