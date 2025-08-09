#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

struct	Data
{
	int			n = 42;
	char		c = '*';
	std::string	str = "Hello, World!";

	bool	operator==(Data const &other);
};

#endif
