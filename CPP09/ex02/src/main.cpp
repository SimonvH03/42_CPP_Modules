#include <iostream>
#include <span>

#include "classes/Timer.hpp"
#include "classes/MergeSort.hpp"
#include "classes/Bucket.hpp"

constexpr	unsigned int	Iterations = 100;

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " \"1*<number>\"\n";
		return (EINVAL);
	}

	Timer::TimePoint	start;
	Timer::TimePoint	end;

	Bucket<Timer::Clock::duration>	dequeBucket;
	Bucket<Timer::Clock::duration>	vectorBucket;

	MergeSort	sortable{std::istringstream(argv[1])};

	for (unsigned int i = 0; i < Iterations; ++i)
	{
		start	= Timer::Clock::now();
		sortable.sort_deque();
		end		= Timer::Clock::now();
		dequeBucket.add(end - start);
		sortable.reset();
	}

	for (unsigned int i = 0; i < Iterations; ++i)
	{
		start	= Timer::Clock::now();
		sortable.sort_vector();
		end		= Timer::Clock::now();
		vectorBucket.add(end - start);
		sortable.reset();
	}

	Timer::report(std::cout << "deque average sort time: ", dequeBucket.average()) << "\n";
	Timer::report(std::cout << "vector average sort time: ", vectorBucket.average()) << "\n";

	return (0);
}
