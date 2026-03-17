#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <sstream>

class ClapTrap
{
	protected:
		ClapTrap();
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &original);
		ClapTrap& operator=(ClapTrap const &original);
		virtual ~ClapTrap();

virtual	void	attack(std::string const &targetName);
		void	recover(unsigned int amount);
virtual	void	takeDamage(unsigned int amount);

		void	setName(std::string const &name);
		void	setHP(unsigned int hp);
		void	setEnergy(unsigned int energy);
		void	setATK(unsigned int atk);

		std::string		getName(void)	const;
		unsigned int	getHP(void)		const;
		unsigned int	getEnergy(void)	const;
		unsigned int	getATK(void)	const;

	protected:
		std::string		Name;
		unsigned int	HP;
		unsigned int	Energy;
		unsigned int	ATK;

		static const unsigned int	attackCost;
		static const unsigned int	recoverCost;

		static const std::string	defaultName;
		static const unsigned int	defaultHP;
		static const unsigned int	defaultEnergy;
		static const unsigned int	defaultATK;
};

std::ostream	&operator<<(std::ostream &os, ClapTrap const &claptrap);

#endif
