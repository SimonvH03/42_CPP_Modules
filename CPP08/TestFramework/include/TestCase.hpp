#ifndef TESTCASE_HPP
# define TESTCASE_HPP
# include <iostream>
# include <string>

class TestCase
{
	public:
		TestCase() = delete;
		explicit	TestCase(std::string const &testName);
		virtual		~TestCase();

		virtual void		run() const = 0;
		std::string const	&getName() const;

	private:
		std::string	_name;
};

#endif
