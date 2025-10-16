#include "TestRunner.hpp"

int	main(void)
{
	TestRunner::get().runAllTests();
	return 0;
}

// EXAMPLE
/* 
#include "TestCreation.hpp"
#include "ValidationTools.hpp"

class wrongInt
{
	public:
		wrongInt() : _n(42) {}
		wrongInt(int n) : _n(n) {}
		wrongInt &operator=(int n) {
			(void)n;
			_n = 42;
			return (*this);
		}
		int	operator+(int n) const {
			(void)n;
			return (_n + 42);
		}
		bool operator==(wrongInt const &other) const {
			return (_n == other._n);
		}
		~wrongInt() = default;
	private:
		int	_n;
};

TEST(exampleAddition) {
	wrongInt i(2);

	CHECK(i + 3 == 5);
}

TEST(exampleEquation) {
	wrongInt i(5);
	wrongInt j;

	j = 5;
	EQUATE(i, j);
}
 */
// example