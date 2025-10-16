#ifndef SPANTEST_HPP
# define SPANTEST_HPP

# include "Span.hpp"
# include <limits>
# include <iostream>
# include <exception>
# include <functional>
// # include <algorithm>

# include <vector>
# include <set>
# include <ranges>

class	Run
{
public:
	template <typename Func>
	bool	runTest(const char *testName, Func testBody);

	template<typename A, typename B>
		requires std::equality_comparable_with<A, B>
	static void	equate(unsigned int testCase, A a, B b);
	static bool	reportPass(const char *testName);
	static bool	reportFail(const char *testName);

private:

	class	inequalityException : public std::exception
	{
		public:
			inequalityException();
			inequalityException(unsigned int id);
			const char *what() const throw();
		private:
			unsigned int	_id;
			std::string		_message;
	};
};

class	SpanTest : public Run
{
public:
	// void	addTest();
	// void	runAllTests();
	static	bool	Constructors();
	static	bool	AssignmentOperator();

private:
	struct	Score {
		unsigned int	passed = 0;
		unsigned int	total = 0;
	}	_score;

	void	scoreSummary();

	// std::vector<std::function &>	_tests;
};

# include "SpanTest.tpp"

#endif
