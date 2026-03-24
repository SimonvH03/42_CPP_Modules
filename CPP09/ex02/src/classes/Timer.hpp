#ifndef TIMER_HPP
# define TIMER_HPP

# include <chrono>
# include <iostream>

namespace Timer
{
	using Clock		= std::chrono::high_resolution_clock;
	using TimePoint	= Clock::time_point;

	std::ostream &report(std::ostream &os, Timer::Clock::duration duration);
}

#endif