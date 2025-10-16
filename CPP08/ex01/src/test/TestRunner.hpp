#ifndef TESTRUNNER_HPP
# define TESTRUNNER_HPP
# include <iostream>
# include <fstream>
# include <memory>
# include <vector>

class TestCase;

class TestRunner
{
public:
	static TestRunner	&get();

	void	addTest(std::unique_ptr<TestCase> test);
	void	runAllTests();

private:
	TestRunner();
	~TestRunner();
	std::vector<std::unique_ptr<TestCase>>	_tests;

	std::ofstream	_logFile;
	void			log(std::unique_ptr<TestCase> const &test, std::exception const &e);
};

#endif
