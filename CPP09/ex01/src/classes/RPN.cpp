#include "RPN.hpp"

namespace ReversePolishNotation
{
	int	calc(std::istringstream expression)
	{
		std::stack<int>	stack;
		std::string	token;

		while (expression >> token) {
			if (token.length() > 1)
				throw std::runtime_error(
					"argument " + token + " consists of too many characters: max 1");

			char	argument = token[0];
			if (std::isdigit(argument)) {
				stack.push(argument - '0');
			} else if (Operations.find(argument) != std::string::npos) {
				if (stack.size() < 2)
					throw std::runtime_error(
						"not enough operands before argument " + token);

				int b = stack.top();
				stack.pop();
				int a = stack.top();
				stack.pop();

				switch (argument) {
					case '+':
						stack.push(a + b);
						break;
					case '-':
						stack.push(a - b);
						break;
					case '*':
						stack.push(a * b);
						break;
					case '/':
						if (b == 0)
							throw std::runtime_error(
								"division by zero is not allowed silly");
						stack.push(a / b);
						break;
					default:
						throw std::logic_error("not all Operations are accounted for in the switch");
				}
			} else
				throw std::runtime_error(
					"argument " + token + " is not a digit (0...9) or operation (+-*/)");
		}

		if (stack.size() != 1)
			throw std::runtime_error(
				"invalid expression: not enough operations");

		return (stack.top());
	}
}