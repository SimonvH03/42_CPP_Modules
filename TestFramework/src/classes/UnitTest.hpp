#ifndef UNITTEST_HPP
# define UNITTEST_HPP
# include <iostream>

class UnitTest
{
	private:

	protected:

	public:
		UnitTest();
		UnitTest(UnitTest const &original);
		UnitTest &operator=(UnitTest const &original);
		~UnitTest();

		class TestAssertionError: public std::exception
		{public:	const char *what() const throw();};
};

#endif
