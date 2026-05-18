#include "MergeInsort.hpp"

template <
	template <
		typename,
		typename...>
		class Container,
	typename Iterator,
	class Comparator>
void
MergeInsort::sort(
	Iterator begin,
	Iterator end,
	Comparator lt)
{
	using	Value	= std::iterator_traits<Iterator>::value_type;
	using	Pair	= std::pair<Value, Value>;

	if (std::distance(begin, end) <= 1)
		return;

	Container<Pair> pairs;

	for (Iterator it = begin; it != end; ++it)
	{
		Value	first = *it++;
		if (it == end) {
			break;
		}
		Value	second = *it;

		if (lt(second, first))
			std::swap(second, first);

		pairs.push_back(std::make_pair(first, second));
	}

	sort<Container>(pairs.begin(), pairs.end(), CompareSecond<Pair>());

	Container<Value> chain;

	for (Pair const &pair : pairs)
		chain.push_back(pair.second);

	chain.insert(chain.begin(), pairs[0].first);

	std::size_t	upper_bound		= pairs.size();
	std::size_t	lower_bound		= 1;
	std::size_t	i_jacobsthal	= 2;

	for (std::size_t j = jacobsthalSequence(++i_jacobsthal);
		j < upper_bound;
		lower_bound = j,
		j = jacobsthalSequence(++i_jacobsthal))
		for (std::size_t i = j - 1;
			i >= lower_bound;
			i--)
			chain.insert(std::lower_bound(chain.begin(), chain.end(), pairs[i].first), pairs[i].first);

	for (std::size_t i = upper_bound - 1;
		i >= lower_bound;
		i--)
		chain.insert(std::lower_bound(chain.begin(), chain.end(), pairs[i].first), pairs[i].first);

	std::copy(chain.begin(), chain.end(), begin);
}

/* {
	S.insert(S.begin(), s[0]);
	std::size_t	upper_bound = s.size();
	std::size_t	lower_bound = 1;
	std::size_t	jacobsthal = 2;
	while (jacobsthalSequence(++jacobsthal) < upper_bound) {
		for (size_t i = jacobsthalSequence(jacobsthal) - 1; i >= lower_bound; i--) {
			S.insert(std::lower_bound(S.begin(), S.end(), s[i]), s[i]);
		}
		lower_bound = jacobsthalSequence(jacobsthal);
	};
	for (size_t i = upper_bound - 1; i >= lower_bound; i--) {
		S.insert(std::lower_bound(S.begin(), S.end(), s[i]), s[i]);
	}
	X = S;
} */