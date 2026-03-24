#include "MergeSort.hpp"

MergeSort::MergeSort(std::istringstream arg)
{
	std::string	token;

	while (arg >> token)
	{
		int	i = std::stoi(token);
		_input.push_back(i);
	}
	 _deque.assign(_input.begin(), _input.end());
	_vector.assign(_input.begin(), _input.end());
}

void
MergeSort::reset()
{
	 _deque.assign(_input.begin(), _input.end());
	_vector.assign(_input.begin(), _input.end());
}

void
MergeSort::sort_deque()
{

}

void
MergeSort::sort_vector()
{

}

template<typename T>
void
MergeSort::sort(T::iterator, T::iterator)
{

}
