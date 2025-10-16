#include <iostream>
#include <vector>

#include "Span.hpp"
#include "SpanTest.hpp"

int main(void)
{
	int	i(0);
	int c(0);

	i += SpanTest::Constructors(); c++;
	i += SpanTest::AssignmentOperator(); c++;
	std::cout << i << "/" << c << " Tests Passed\n" << ((i < c) ? "suck it" : "good job") << "\n";
}
