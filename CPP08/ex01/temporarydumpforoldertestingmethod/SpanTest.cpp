#include "SpanTest.hpp"

bool	Run::reportPass(char const *testName)
{
	std::cout << testName << ": \e[32mPass\e[0m\n";
	return (true);
}

bool	Run::reportFail(char const *testName)
{
	std::cout << testName << ": \e[31mFail\e[0m\n";
	return (false);
}

SpanTest::inequalityException::inequalityException(unsigned int id)
	:	_id(id)
	,	_message("Test " + std::to_string(_id)
		+ ": Compared result does not equal expected result")
{};

SpanTest::inequalityException::inequalityException()
	:	_id(0)
	,	_message("Compared result does not equal expected result")
{};

const char	*SpanTest::inequalityException::what() const throw()
{
	return (_message.data());
}

bool	SpanTest::Constructors()
{
	char const	testName[] = "Constructors";
	try {
		Span	span0;
		Span	span1(0);
		Span	span2(42);
		Span	span3(std::numeric_limits<unsigned int>::max());
		Span	span4(-1);

		Run::equate(0, span0.getSize(), static_cast<unsigned int>(0));
		Run::equate(1, span1.getSize(), static_cast<unsigned int>(0));
		Run::equate(2, span2.getSize(), static_cast<unsigned int>(42));
		Run::equate(3, span3.getSize(), std::numeric_limits<unsigned int>::max());
		Run::equate(4, span4.getSize(), static_cast<unsigned int>(-1));

		Span	copy0(span0);
		Span	copy1(span1);
		Span	copy2(span2);
		Span	copy3(span3);
		Span	copy4(span4);

		Run::equate(5, copy0, span0);
		Run::equate(6, copy1, span1);
		Run::equate(7, copy2, span2);
		Run::equate(8, copy3, span3);
		Run::equate(9, copy4, span4);

		std::vector<int> vector(1000, 0);
		std::srand(time(NULL));
		std::ranges::generate(vector, std::rand);

		std::set<int> set(vector.begin(), vector.end());

		Span	span5(vector.begin(), vector.end());
		Span	span6(vector);
		Span	span7(set.begin(), set.end());

		Run::equate(10, span5, vector);
		Run::equate(11, span6, vector);
		Run::equate(12, span7, set);
	}	catch (std::exception const &e) {
		std::cerr << "Error: " << testName << ": " << e.what() << std::endl;
		return (Run::reportFail(testName));
	}
	return (Run::reportPass(testName));
}

bool	SpanTest::AssignmentOperator()
{
	char const	testName[] = "AssignmentOperator";
	try {
		std::vector<int>	vector({0,42,-1,std::numeric_limits<int>::max()});
		Span				span0(vector);

		Span	copy0 = span0;

		Run::equate(0, copy0, span0);

		Span	span1;
		Span	span2;
		Span	span3;
		Span	span4;

		span1 = span0;
		span3.operator=(span0);
		span2 = vector;
		span4.operator=(vector);

		// vector[0] = 42;
		Run::equate(1, span1, span0);
		Run::equate(2, span2, span0);
		Run::equate(3, span3, vector);
		Run::equate(4, span4, vector);
	}	catch (std::exception const &e) {
		std::cerr << "Error: " << testName << ": " << e.what() << std::endl;
		return (Run::reportFail(testName));
	}
	return (Run::reportPass(testName));
}


