#include "Timer.hpp"

namespace Timer
{
	std::ostream &
	report(std::ostream &os, Timer::Clock::duration duration)
	{
		os	<< duration
			<< " : " << std::chrono::duration_cast<std::chrono::microseconds>(duration)
			<< " : " << std::chrono::duration_cast<std::chrono::milliseconds>(duration);
		return (os);
	}
}
