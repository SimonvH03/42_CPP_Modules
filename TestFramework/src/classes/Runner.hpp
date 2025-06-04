#ifndef RUNNER_HPP
# define RUNNER_HPP
# include <iostream>

class Runner
{
	private:

	protected:

	public:
		Runner();
		Runner(Runner const &original);
		Runner &operator=(Runner const &original);
		~Runner();
};

#endif
