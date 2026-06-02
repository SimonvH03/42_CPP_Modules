#include <iostream>
#include <span>

#include "classes/Timer.hpp"
#include "classes/MergeInsort.hpp"
#include "classes/Bucket.hpp"

constexpr	unsigned int	Samples = 10000;

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " \"1*<number>\"\n";
		return (EINVAL);
	}

	std::vector<int>	input;
	std::istringstream	arg(argv[1]);
	std::string			token;

	while (arg >> token)
	{
		try {
			int	i = std::stoi(token);
			input.push_back(i);
		} catch (std::invalid_argument &e) {
			std::cerr << "Error\n"
				<< "Invalid Element: " << token << "\n"
				<< "In Argument: \"" << argv[1] << "\"\n";
			return (EINVAL);
		}
	}

	MergeInsort	sortable;

	Timer::TimePoint	start;
	Timer::TimePoint	end;

	Bucket<Timer::Clock::duration>	dequeBucket;
	Bucket<Timer::Clock::duration>	vectorBucket;

	for (unsigned int i = 0; i < Samples; ++i)
	{
		sortable.set(input);
		start	= Timer::Clock::now();
		sortable.sort_deque();
		end		= Timer::Clock::now();
		dequeBucket.add(end - start);

		start	= Timer::Clock::now();
		sortable.sort_vector();
		end		= Timer::Clock::now();
		vectorBucket.add(end - start);
	}

	std::cout << "Sorted:";
	for (int n : sortable.getVector())
		std::cout << " " << n;
	std::cout << "\n";

	Timer::report(std::cout << "deque  average sort time: ", dequeBucket.average()) << "\n";
	Timer::report(std::cout << "vector average sort time: ", vectorBucket.average()) << "\n";
	std::cout << "(" << Samples << " Samples)\n";

	return (0);
}
