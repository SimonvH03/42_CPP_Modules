#include "Harl.hpp"

const std::string
	Harl::_levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"};

const Harl::thought
	Harl::_thoughts[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

Harl::Harl()
{
}

Harl::~Harl()
{
}

int		Harl::getLevel(std::string level)
{
	if (level.empty())
		return (-1);
	int	i = 0;
	while (i < 4 && _levels[i].compare(level))
		i++;
	if (i == 4)
		return (-1);
	return (i);
}

void	Harl::complain(std::string level)
{

	if (level.empty())
	{
		std::cout << '\n';
		return ;
	}
	int	i = getLevel(level);
	if (i != -1)
	{
		(this->*_thoughts[i])();
	}
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
		<< "\tYou didn't put enough bacon in my burger!\n\tIf you did, I wouldn't be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\n"
		<< "\tI've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
