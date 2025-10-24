#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <sstream>

class ClapTrap
{
	protected:
		ClapTrap();

		std::string		Name;
		unsigned int	HP;
		unsigned int	Energy;
		unsigned int	ATK;

	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &original);
		ClapTrap& operator=(ClapTrap const &original);
		virtual ~ClapTrap();
		
virtual	void	attack(std::string const &targetName);
		void	recover(unsigned int amount);
virtual	void	takeDamage(unsigned int amount);

		void	setName(std::string name);
		void	setHP(unsigned int hp);
		void	setEnergy(unsigned int energy);
		void	setATK(unsigned int atk);
virtual std::string		status();
		std::string		getName(void) const;
		unsigned int	getHP(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getATK(void) const;
};

#endif
