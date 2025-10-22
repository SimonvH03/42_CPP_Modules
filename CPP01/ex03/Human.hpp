#ifndef HUMAN_HPP
# define HUMAN_HPP
# include <iostream>

class	Human
{
	public:
		Human(std::string const &name);
		~Human();

		virtual void	attack() const = 0;

	protected:
		std::string	_name;
};

#endif
