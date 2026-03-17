#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	const std::string	DataBasePath("data.csv");
	const std::string	Format("date,exchange_rate");
	const char			Delimiter(',');

	// std::cout << "BitcoinExchange Default Constructor\n";

	std::ifstream	dataBaseContent(DataBasePath);
	std::string		line;

	std::getline(dataBaseContent, line);
	if (line != Format)
		throw std::runtime_error("line 0: " + line + "\nexpected: " + Format);

	for (int i = 0; std::getline(dataBaseContent, line); ++i) {
		std::size_t	delim;
		std::tm		date{};
		std::time_t	time;
		float		value;

		delim = line.find(Delimiter);
		if (delim == std::string::npos)
			throw std::runtime_error("line " + std::to_string(i) + ": " + line
				+ "\nmissing delimiter");

		std::istringstream	ss(line.substr(0, delim));
		ss >> std::get_time(&date, "%Y-%m-%d");
		if (ss.fail())
			throw std::runtime_error("line " + std::to_string(i) + ": " + line
				+ "\ndate invalid [YYYY-mm-dd]");
		time = std::mktime(&date);

		try	{
			value = std::stof(line.substr(delim + 1));
			if (value < 0)
				throw std::runtime_error("line " + std::to_string(i) + ": " + line
					+ "\nvalue out of range [0 - inff]");
		} catch (std::invalid_argument &e) {
			throw std::runtime_error("line " + std::to_string(i) + ": " + line
				+ "\nexchange_rate invalid [float]");
		} catch (std::out_of_range &e) {
			throw std::runtime_error("line " + std::to_string(i) + ": " + line
				+ "\nexchange_rate out of range [float]");
		}

		if (_dataBase.contains(time))
			throw std::runtime_error("line " + std::to_string(i) + ": " + line
				+ "\nduplicate date entry");
		else
			_dataBase.insert({time, value});
	}
}

std::string
BitcoinExchange::reportLine(std::string const &line)
const {
	const char	Delimiter('|');

	std::size_t	delim;
	std::time_t	time;
	float		value;

	delim = line.find(Delimiter);
	if (delim == std::string::npos)
		return ("Error: missing delimiter");

	{	std::tm				date{};
		std::istringstream	ss(line.substr(0, delim));

		ss >> std::get_time(&date, "%Y-%m-%d");
		if (ss.fail())
			return ("Error: date invalid [YYYY-mm-dd]");

		time = std::mktime(&date);
	}

	try	{
		value = std::stof(line.substr(delim + 1));
		if (value < 0 || value > 1000)
			return ("Error: value out of range [0 - 1000]");
	} catch (std::out_of_range &e) {
			return ("Error: value out of range [0 - 1000]");
	} catch (std::invalid_argument &e) {
			return ("Error: value invalid [float]");
	}

	{	std::stringstream	output;

		output <<	line.substr(0, delim + 1)
			<<		std::setprecision(5)
			<<		std::setw(8) << value << ": "
			<<		getExchangeRate(time) * value;

		return (output.str());
	}
}

void
BitcoinExchange::report(std::string const &file)
const {
	const std::string	Format("date | value");

	// std::cout << "BitcoinExchange::report()\n";

	std::ifstream	content(file);
	std::string		line;

	std::getline(content, line);
	if (line != Format)
		throw std::runtime_error(line + "\nexpected: " + Format);

	while (std::getline(content, line))
		std::cout << reportLine(line) << "\n";
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &original)
{
	// std::cout << "BitcoinExchange Copy Constructor\n";
	*this = original;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &original)
{
	// std::cout << "BitcoinExchange Assignment Operator\n";
	if (this != &original) {
		_dataBase = original._dataBase;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange Destructor\n";
}

float
BitcoinExchange::getExchangeRate(std::time_t time)
const {
	return (_dataBase.contains(time)
		?	_dataBase.at(time)
		:	(--_dataBase.lower_bound(time))->second);
}
