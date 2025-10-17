#ifndef TESTCASE_HPP
# define TESTCASE_HPP
# include <iostream>
# include <string>

class TestCase
{
	public:
		virtual ~TestCase();
		TestCase(std::string const &testName);

		std::string const	&getName() const;

		virtual void run() const = 0;

	private:
		std::string _name;
};

#endif
