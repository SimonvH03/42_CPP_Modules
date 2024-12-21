#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>

class Ice
{
	private:

	protected:

	public:
		Ice();
		Ice(Ice const &original);
		Ice &operator=(Ice const &original);
		~Ice();
};

#endif
