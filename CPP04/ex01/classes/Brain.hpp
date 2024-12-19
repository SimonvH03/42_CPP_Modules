#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	private:
		int		levelOfThought;

	public:
		Brain();
		Brain(Brain const &original);
		Brain &operator=(Brain const &original);
		~Brain();

		std::string	ideas[100];

		void	inspire(std::string inspiration);
		void	inception(Brain *dest) const;
};

#endif
