#ifndef Harl_HPP
# define Harl_HPP
# include <iostream>

class Harl
{
	private:
		typedef	void		(Harl::*thought) (void);

	public:
		Harl();
		~Harl();
		int		getLevel(std::string);
		void	complain(std::string level);

		static std::string	_levels[];
		static thought		_thoughts[];

	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
};

#endif
