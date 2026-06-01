#ifndef MERGEINSORT_HPP
# define MERGEINSORT_HPP

# include <sstream>
# include <deque>
# include <vector>
# include <algorithm>

class	MergeInsort
{
	public:
		MergeInsort()	= default;
		~MergeInsort()	= default;

	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

	public:
		template <typename T>
		void	set(T &toSort);

		void	sort_vector();
		void	sort_deque();

		std::vector<int> const	&getVector() const;
		std::deque<int>  const	&getDeque()  const;

		std::size_t	jacobsthalSequence(std::size_t n);

	private:
		template <typename T>
		void sort(T &container);
};

# include "MergeInsort.tpp"

#endif