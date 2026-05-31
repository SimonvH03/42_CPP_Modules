#ifndef MERGEINSORT_HPP
# define MERGEINSORT_HPP

# include <sstream>
# include <deque>
# include <vector>
# include <algorithm>

class	MergeInsort
{
	private:
		struct {
			int	value;
			int	index;
		}	IndexedValue;

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
		template <typename T>
		void sort(T container);

		template <typename T>
		void sortIndexed(T container);
};

# include "MergeInsort.tpp"

#endif