#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constructor\n";
}

ScalarConverter::ScalarConverter(ScalarConverter const &original)
{
	std::cout << "ScalarConverter Copy Constructor\n";
	*this = original;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &original)
{
	std::cout << "ScalarConverter Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor\n";
}

// private exception
ScalarConverter::RangeException::RangeException(const std::string& message)
{
	_message = message;
}

// public
int	ScalarConverter::convert(const std::string &string)
{
	convertToChar(string);
	convertToInt(string);
	convertToFloat(string);
	convertToDouble(string);
	return (0);
}

// private
char ScalarConverter::convertToChar(const std::string &string)
{
	if (string.length() == 1)
	{
		return (string[0]);
	}
	else
	{
		const int	value = std::atoi(string.c_str());

		if (value < 0 || value > 127)
			throw (RangeException("Out of range 0,127"));
	}
}

int ScalarConverter::convertToInt(const std::string &string)
{

}

float ScalarConverter::convertToFloat(const std::string &string)
{

}

double ScalarConverter::convertToDouble(const std::string &string)
{

}
