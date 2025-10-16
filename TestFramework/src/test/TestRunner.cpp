#include "TestRunner.hpp"
#include "TestCase.hpp"

TestRunner::TestRunner()
	:	_logFile("FailLog.txt", std::ios::out | std::ios::trunc)
{
#ifdef VERBOSE
	std::cout << "TestRunner Default Constructor\n";
#endif

	if (!_logFile.is_open())
		throw std::ios_base::failure("TestRunner failed to create Log file");
	_logFile << "time: " << time(NULL) << "\n\n";
}

TestRunner::~TestRunner()
{
#ifdef VERBOSE
	std::cout << "TestRunner Destructor\n";
#endif

	_logFile.close();
}

TestRunner&	TestRunner::get()
{
#ifdef VERBOSE
	std::cout << "TestRunner get()\n";
#endif

	static TestRunner	instance;
	return (instance);
}

void	TestRunner::addTest(std::unique_ptr<TestCase> test)
{
#ifdef VERBOSE
	std::cout << "TestRunner addTest()\n";
#endif

	_tests.push_back(std::move(test));
}

void	TestRunner::runAllTests()
{
#ifdef VERBOSE
	std::cout << "TestRunner runAllTests()\n";
#endif

	unsigned int	total = _tests.size();
	unsigned int	passed = 0;
	unsigned int	ran = 0;

	std::cout << "running " << total << " tests...\n";
	if (total == 0) return ;
	for (std::unique_ptr<TestCase> const &test : _tests)
	{
		try {
			test->run();
			std::cout	<< "(" << ran+1 << ") \e[32m[PASS]\e[33m " << test->getName() << "\e[0m\n";
			++passed;
		} catch (std::exception const &e) {
			std::cout	<< "(" << ran+1 << ") \e[31m[FAIL]\e[33m " << test->getName() << "\e[0m\n";
			log(test, e);
		} ++ran;
	}
	std::cout << passed << "/" << ran << " tests passed.\n";
	_logFile << ran - passed << "/" << ran << " tests failed.";
}

void	TestRunner::log(std::unique_ptr<TestCase> const &test, std::exception const &e)
{
#ifdef VERBOSE
	std::cout << "TestRunner log()\n";
#endif

	_logFile << test->getName() << ":\n\t" << e.what() << "\n\n";
}
