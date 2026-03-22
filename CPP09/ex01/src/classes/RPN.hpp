#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>

namespace ReversePolishNotation
{
	constexpr std::string	Operations("+-*/");

	int	calc(std::istringstream expression);
};

#endif
