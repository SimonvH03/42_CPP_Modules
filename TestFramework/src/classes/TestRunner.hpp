#ifndef TESTRUNNER_HPP
# define TESTRUNNER_HPP
# include <vector>
# include <memory>
# include <iostream>
# include "TestCase.hpp"

class TestRunner
{
	public:
		static TestRunner& get();
		void add(std::unique_ptr<TestCase> test);
		void runAll();

	private:
		std::vector<std::unique_ptr<TestCase>> tests;
};

#endif