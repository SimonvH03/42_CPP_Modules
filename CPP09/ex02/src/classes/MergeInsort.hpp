#ifndef MERGEINSORT_HPP
# define MERGEINSORT_HPP

# include <sstream>
# include <deque>
# include <vector>
# include <algorithm>

class	MergeInsort
{
	private:
		template <typename T>
		struct CompareSecond {
			bool operator()(const T& a, const T& b) const {
				return a.second < b.second;
			}
		};

	public:
		MergeInsort(std::istringstream arg);
		~MergeInsort() = default;

	private:
		std::vector<int>	_input;

		std::vector<int>	_vector;
		std::deque<int>		_deque;

	public:
		void	reset();

		void	sort_vector();
		void	sort_deque();

		std::vector<int> const	&getVector() const;
		std::deque<int>  const	&getDeque()  const;

		std::size_t	jacobsthalSequence(std::size_t n);

	private:
		template <
			template <
				typename,
				typename...>
				class Container,
			typename Iterator,
			class Comparator>
		void sort(
			Iterator begin,
			Iterator end,
			Comparator lt);
};

# include "MergeInsort.tpp"

#endif