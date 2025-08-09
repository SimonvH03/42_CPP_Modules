#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int>	numbers(MAX_VAL);
	int			*mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	{
		Array<int> tmp;
		tmp = numbers;
		Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i]
				|| tmp[i] != numbers[i]
				|| test[i] != numbers[i])
			{
				std::cerr << "Value incorrectly assigned / copied: "
					<< numbers[i] << ", arr[n] = value: "
					<< mirror[i] << ", arr = original: "
					<< tmp[i] << ", arr(original): "
					<< test [i] << std::endl;
				return 1;
			}
		}
	}

	try {
		numbers[-2] = 0;// expect: index out of range
	} catch(std::exception const &except) {
		std::cerr << except.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;// expect: index out of range
	} catch(std::exception const &except) {
		std::cerr << except.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	delete [] mirror;
	return 0;
}
