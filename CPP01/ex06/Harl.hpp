#ifndef Harl_HPP
# define Harl_HPP
# include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
		int		getLevel(std::string);

		static const size_t	n_lvl = 4;
		std::string			levels[n_lvl];

	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
};

typedef	void	(Harl::*thought) (void);

#endif
