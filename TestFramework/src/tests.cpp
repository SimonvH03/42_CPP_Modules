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

// addNumber(), addRange(Range), addRange(Iterator Range), shortestSpan(), longestSpan()
