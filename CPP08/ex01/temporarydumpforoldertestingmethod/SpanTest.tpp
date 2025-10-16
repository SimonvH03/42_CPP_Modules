#ifndef SPANTEST_TPP
# define SPANTEST_TPP

template <typename Func>
bool	Run::runTest(const char *testName, Func testBody)
{
	try {
		testBody();
		return (reportPass(testName));
	}	catch (std::exception const &e) {
		std::cerr << "Error: " << testName << ": " << e.what() << std::endl;
		return (reportFail(testName));
	}
	catch (...) {
		std::cerr << "Error: " << testName << ": Unknown exception\n";
		return (reportFail(testName));
	}
}

template<typename A, typename B>
	requires std::equality_comparable_with<A, B>
void	Run::equate(unsigned int testCase, A a, B b)
{
	if (a != b)
		throw inequalityException(testCase);
}

#endif
