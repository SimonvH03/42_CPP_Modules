#include "MergeInsort.hpp"

template <typename T>
void
MergeInsort::set(
	T &toSort)
{
	_vector.assign(toSort.begin(), toSort.end());
	 _deque.assign(toSort.begin(), toSort.end());

	(void)jacobsthalSequence(toSort.size());
}

template <typename T>
void
MergeInsort::sort(
	T &container)
{
	if (container.size() <= 1)
		return;

	using Iterator = typename T::iterator;

	T B{container.begin(), container.begin() + container.size() / 2};
	T A{container.begin() + container.size() / 2, container.end()};

/* 	for (Iterator bit = B.begin(), Iterator ait = A.begin();
		bit != B.end();
		++bit, ++ait)
		if (*bit < *ait)
			std::swap(*ait, *bit);
*/	{
		Iterator bit = B.begin();
		Iterator ait = A.begin();
		while (bit != B.end()) {
			if (*bit < *ait)
				std::swap(*ait, *bit);
			++bit;
			++ait;
		}
	}

	T b(B);
	T a(A);

	sort(b);
	for (size_t i = 0;
		i < B.size();
		++i)
		for (size_t k = 0;
			k < b.size();
			++k)
			if (b[k] == B[i])
				B[i] = -1, a.at(k) = A[i];

	b.insert(b.begin(), a[0]);

	std::size_t	upper_bound		= a.size();
	std::size_t	lower_bound		= 1;
	std::size_t	i_jacobsthal	= 2;

	for (std::size_t j = jacobsthalSequence(++i_jacobsthal);
		j < upper_bound;
		lower_bound = j,
		j = jacobsthalSequence(++i_jacobsthal))
		for (std::size_t i = j - 1;
			i >= lower_bound;
			i--)
			b.insert(std::lower_bound(b.begin(), b.end(), a[i]), a[i]);

	for (std::size_t i = upper_bound - 1;
		i >= lower_bound;
		i--)
		b.insert(std::lower_bound(b.begin(), b.end(), a[i]), a[i]);

	container = b;
}
