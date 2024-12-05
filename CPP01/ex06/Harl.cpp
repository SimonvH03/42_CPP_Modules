#include "Harl.hpp"

Harl::Harl()
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

Harl::~Harl()
{
}

int		Harl::getLevel(std::string level)
{
	if (level.empty())
		return (-1);
	int	i = 0;
	while (i < 4 && levels[i].compare(level))
		i++;
	if (i == 4)
		return (-1);
	return (i);
}

void	Harl::complain(std::string level)
{
	thought		thoughts[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (level.empty())
	{
		std::cout << '\n';
		return ;
	}
	int	i = getLevel(level);
	if (i != -1)
	{
		(this->*thoughts[i])();
	}
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!\n"
		<< "If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\n"
		<< "I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
