#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		typedef	typename std::deque<T>::iterator		iterator;
		typedef	typename std::deque<T>::const_iterator	const_iterator;

		iterator	begin();
		iterator	end();

		const_iterator	begin() const;
		const_iterator	end() const;
};

# include "MutantStack.tpp"

#endif
