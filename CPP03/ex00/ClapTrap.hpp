#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &original);
		ClapTrap& operator=(ClapTrap const &original);
		~ClapTrap();
		
		void	attack(std::string const &targetName);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	status();
		void	setName(std::string name);
		void	setHP(unsigned int hp);
		void	setEnergy(unsigned int energy);
		void	setATK(unsigned int atk);
		std::string		getName(void);
		unsigned int	getHP(void);
		unsigned int	getEnergy(void);
		unsigned int	getATK(void);
	private:
		std::string		Name;
		unsigned int	HP;
		unsigned int	Energy;
		unsigned int	ATK;
};

#endif
