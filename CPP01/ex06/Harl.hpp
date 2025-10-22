#ifndef Harl_HPP
# define Harl_HPP
# include <iostream>

class Harl
{
	public:
		static void	complain(std::string level);

		static const	std::string	_levels[];
		static	int		getLevelIndex(std::string const &level);

	private:
		typedef	void	(*thought)();
		static const	thought		_thoughts[];

		static	void	debug();
		static	void	info();
		static	void	warning();
		static	void	error();
};

#endif
