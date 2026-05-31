#include "MergeInsort.hpp"

template <typename T>
void
MergeInsort::sort(
	T container)
{
	if (container.size() <= 1)
		return;

	T B{container.begin(), container.begin() + container.size() / 2};
	T A{container.begin() + container.size() / 2, container.end()};

	for (T::iterator bit = B.begin(), T::iterator ait = A.begin();
		bit != B.end();
		++bit, ++ait)
		if (*bit < *ait)
			std::swap(*ait, *bit);

	T b(B);
	T a(A);

	sort(b);
	for (size_t i = 0;
		i < B.size();
		++i)
		for (size_t j = 0;
			j < b.size();
			++j)
			if (B[i] == b[j])
				b[j] = -1, a.at(i) = A[j];


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