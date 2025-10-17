#include "TestCreation.hpp"
#include "ValidationTools.hpp"

#include "Span.hpp"

#include <limits>
#include <vector>
#include <set>

TEST(Call_Default_Constructor) {
	Span	span;
}

TEST(Call_Size_Constructor) {
	{	Span	span(0);
	}
	{	Span	span(42);
	}
	{	Span	span(std::numeric_limits<unsigned int>::max());
	}
}

TEST(Call_Copy_Constructor) {
	Span	span;
	Span	copy(span);
}

TEST(Call_Assignment_Operator) {
	Span	span;
	Span	assign;
	assign = span;
}

TEST(Call_getSize) {
	Span	span;
	span.getSize();
}

TEST(Valid_Size_Constructor) {
	{	const unsigned int	size = 0;
		Span	span(size);
		CHECK(span.getSize() == size);
	}
	{	const unsigned int	size = 42;
		Span	span(size);
		CHECK(span.getSize() == size);
	}
	{	const unsigned int	size = std::numeric_limits<unsigned int>::max();
		Span	span(size);
		CHECK(span.getSize() == size);
	}
}

TEST(Valid_Default_Size) {
	Span	span;
	CHECK(span.getSize() == 0);
}

TEST(Call_getVector) {
	Span	span;
	span.getVector();
}

TEST(Valid_Default_Vector) {
	std::vector<int>	vector;
	Span	span;
	CHECK(span.getVector() == vector);
}

TEST(Call_Range_Constructor) {
	std::set<int>	set;
	Span	span(set);
}

TEST(Call_Range_Assignment_Operator) {
	std::set<int>	set;
	Span	span;
	span = set;
}

TEST(Call_Range_Equality_Comparison_Operator) {
	Span	span;
	std::set<int>	set;
	span == set;
	span != set;
}

TEST(Call_Iterator_Range_Constructor) {
	std::vector<int>	vector;
	Span	span(vector.begin(), vector.end());
}

TEST(Valid_Range_Constructor) {
	{	std::vector<int>	vector;
		Span	span(vector);
		CHECK(span == vector);
	}
	{	std::vector<int> vector(1000, 0);
		std::srand(time(NULL));
		std::ranges::generate(vector, std::rand);
		Span	span(vector);
		CHECK(span == vector);
	}
}

TEST(Valid_Range_Assignment_Operator) {
	{	std::vector<int>	vector;
		Span	span(vector.size());
		span = vector;
		CHECK(span == vector);
	}
	{	std::vector<int> vector(1000, 0);
		std::srand(time(NULL));
		std::ranges::generate(vector, std::rand);
		Span	span(vector.size());
		span = vector;
		CHECK(span == vector);
	}
}

TEST(Valid_Iterator_Range_Constructor) {
	{	std::vector<int>	vector;
		Span	span(vector.begin(), vector.end());
		CHECK(span == vector);
	}
	{	std::vector<int> vector(1000, 0);
		std::ranges::generate(vector, std::rand);
		std::srand(time(NULL));
		Span	span(vector.begin(), vector.end());
		CHECK(span == vector);
	}
}

TEST(Valid_Equality_Comparison_Operator) {
	{	Span	span(42);
		{	Span	equal(42);
			CHECK(span == equal);
		}
		{	Span	inequal(43);
			CHECK(span != inequal);
		}
	}
	{	std::vector<int> vector(1000, 0);
		std::srand(time(NULL));
		std::ranges::generate(vector, std::rand);
		Span	span(vector);
		{	Span	equal(vector);
			CHECK(span == equal);
		}
		{	Span	inequal(vector.size());
			CHECK(span != inequal);
		}
		{	Span	inequal(1001);
			inequal = vector;
			CHECK(span != inequal);
		}
	}
}

TEST(Call_addNumber) {
	Span	span(1);
	span.addNumber(42);
}

TEST(Except_addNumber) {
	Span	span;
	try {
		span.addNumber(42);
		throw validationToolsException("expected addnumber() exception");
	} catch (Span::StorageFullException const &e) {}
}

TEST(Valid_addNumber) {
	Span	span(1);
	span.addNumber(42);
	CHECK(span.getVector().at(0) == 42);
}

TEST(Call_addRange) {
	std::vector<int>	vector{0, 42, -1};
	{	Span	span(3);
		span.addRange(vector);
	}
	{	Span	span(3);
		span.addRange(vector.begin(), vector.end());
	}
}

TEST(Except_addRange) {
	std::vector<int>	vector{0, 42, -1};
	try {
		Span	span(2);
		span.addRange(vector);
		throw validationToolsException("expected addRange() exception");
	} catch (Span::StorageFullException const &e) {}
	try {
		Span	span(2);
		span.addRange(vector.begin(), vector.end());
		throw validationToolsException("expected addRange() exception");
	} catch (Span::StorageFullException const &e) {}
	try {
		Span	span(5);
		span.addRange(vector);
		span.addRange(vector);
		throw validationToolsException("expected addRange() exception");
	} catch (Span::StorageFullException const &e) {}
}

TEST(Valid_addRange) {
	std::vector<int>	vector1{0, 42, -1};
	std::vector<int>	vector2{3, 19, -400};
	std::vector<int>	combined{0, 42, -1, 3, 19, -400};
	{	Span	span(6);
		span.addRange(vector1);
		span.addRange(vector2);
		EQUATE(span, combined);
	}
	{	Span	span(6);
		span.addRange(vector1.begin(), vector1.end());
		span.addRange(vector2.begin(), vector2.end());
		EQUATE(span, combined);
	}
}

TEST(Call_shortestSpan) {
	Span	span(std::vector<int>{0, 42});
	span.shortestSpan();
}

TEST(Except_shortestSpan) {
	try {
		Span	span;
		span.shortestSpan();
		throw validationToolsException("expected shortestSpan() exception");
	} catch (Span::SpanningTakesTwo const &e) {}
	try {
		Span	span(std::vector<int>{42});
		span.shortestSpan();
		throw validationToolsException("expected shortestSpan() exception");
	} catch (Span::SpanningTakesTwo const &e) {}
}

TEST(Valid_shortestSpan) {
	{	Span	span(std::vector<int>{0, 42});
		CHECK(span.shortestSpan() == 42);
	}
	{}
}

// longestSpan()
