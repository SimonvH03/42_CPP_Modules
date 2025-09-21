#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange Default Constructor\n";
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &original)
{
	std::cout << "BitcoinExchange Copy Constructor\n";
	*this = original;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &original)
{
	std::cout << "BitcoinExchange Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange Destructor\n";
}
