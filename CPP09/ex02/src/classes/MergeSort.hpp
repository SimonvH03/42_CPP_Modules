#ifndef MERGESORT_HPP
# define MERGESORT_HPP

# include <sstream>
# include <deque>
# include <vector>

class	MergeSort
{
	public:
		MergeSort(std::istringstream arg);
		~MergeSort() = default;

	private:
		std::vector<int>	_input;
		std::deque<int>		_deque;
		std::vector<int>	_vector;

	public:
		void	sort_deque();
		void	sort_vector();

		void	reset();

	private:
		template <typename T>
		void	sort(T::iterator, T::iterator);
};

#endif