#ifndef Harl_HPP
# define Harl_HPP
# include <iostream>

class Harl
{
	public:
		static void	complain(std::string level);

	private:
		typedef	void	(*thought)();

		static const	thought		_thoughts[];
		static const	std::string	_levels[];

		static	void	debug();
		static	void	info();
		static	void	warning();
		static	void	error();

		static	int	getLevelIndex(std::string const &level);
};

#endif
