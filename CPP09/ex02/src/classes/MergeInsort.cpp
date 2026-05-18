#include "MergeInsort.hpp"

MergeInsort::MergeInsort(std::istringstream arg)
{
	std::string	token;

	while (arg >> token)
	{
		int	i = std::stoi(token);
		_input.push_back(i);
	}
}

void
MergeInsort::reset()
{
	_vector.assign(_input.begin(), _input.end());
	 _deque.assign(_input.begin(), _input.end());
}

void MergeInsort::sort_deque() {
	sort<std::deque>(_deque.begin(), _deque.end(), std::less<int>());
}

void MergeInsort::sort_vector() {
	sort<std::vector>(_vector.begin(), _vector.end(), std::less<int>());
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
