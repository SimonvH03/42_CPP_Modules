#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <ctime>
# include <locale>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &original);
		BitcoinExchange &operator=(BitcoinExchange const &original);
		~BitcoinExchange();

	private:
		std::map<std::time_t, float>	_dataBase;

	public:
		void	report(std::string const &file) const;

	private:
		std::string	reportLine(std::string const &line) const;
		float		getExchangeRate(std::time_t date) const;
};

#endif
