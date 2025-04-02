#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	private:
		ClapTrap();

		std::string		Name;
		unsigned int	HP;
		unsigned int	Energy;
		unsigned int	ATK;

	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &original);
		ClapTrap& operator=(ClapTrap const &original);
		~ClapTrap();

		void	attack(std::string const &targetName);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void			status() const;
		std::string		getName(void) const;
		unsigned int	getHP(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getATK(void) const;

		void	setName(std::string name);
		void	setHP(unsigned int hp);
		void	setEnergy(unsigned int energy);
		void	setATK(unsigned int atk);
};

#endif
