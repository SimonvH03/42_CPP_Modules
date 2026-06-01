#include "MergeInsort.hpp"

void MergeInsort::sort_deque() {
	sort(_deque);
}

void MergeInsort::sort_vector() {
	sort(_vector);
}

std::size_t
MergeInsort::jacobsthalSequence(std::size_t n)
{
	static std::vector<std::size_t>	memo({0, 1});

	std::size_t	i = memo.size() - 1;

	if (i > n) {
		while (i < n) {
			memo.push_back((1 << (i)) - memo[i]);
			++i;
		}
	}

	return (memo[n]);
}

std::vector<int> const &MergeInsort::getVector() const {
	return (_vector);
}

std::deque<int> const &MergeInsort::getDeque() const {
	return (_deque);
}
