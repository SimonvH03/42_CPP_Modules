#include "TestRunner.hpp"

TestRunner&	TestRunner::get()
{
	static TestRunner	instance;
	return (instance);
}

void	TestRunner::add(std::unique_ptr<TestCase> test)
{
	tests.push_back(std::move(test));
}

void	TestRunner::runAll()
{
	int	passed = 0;

	for (const auto& test : tests)
	{
		try
		{
			test->run();
			std::cout << "[PASS] " << test->getName() << "\n";
			++passed;
		}
		catch (const std::exception& e)
		{
			std::cout << "[FAIL] " << test->getName() << " - " << e.what() << "\n";
		}
	}
	std::cout << "\n" << passed << "/" << tests.size() << " tests passed.\n";
}
