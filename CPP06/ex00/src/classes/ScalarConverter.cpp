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

void	ScalarConverter::convert(const std::string &input)
{
	if (representsChar(input))
	{
		convertFromChar(input[1]);
		return ;
	}
	if (representsInt(input))
	{
		try {convertFromInt(std::stoi(input));
		} catch (...) {
			std::cout << "Error\nInt out of range\n";
		} return ;
	}
	if (representsFloat(input))
	{
		try {convertFromFloat(std::stof(input));
		} catch (...) {
			std::cout << "Error\nFloat out of range\n";
		} return ;
	}
	if (representsDouble(input))
	{
		try {convertFromDouble(std::stod(input));
		} catch (...) {
			std::cout << "Error\nDouble out of range\n";
		} return ;
	}
	std::cout << "Error\nUnknown Format\n";
}

bool ScalarConverter::representsChar(const std::string& literal)
{
	return (literal.length() == 3 
		&& literal.front() == '\''
		&& literal.back() == '\'');
}

bool ScalarConverter::representsInt(const std::string& literal)
{
	char	*end = nullptr;

	std::strtol(literal.c_str(), &end, 10);
	return (*end == '\0');
}

bool ScalarConverter::representsFloat(const std::string& literal)
{
	if (literal.back() != 'f')
		return (false);
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return (true);

	char	*end = nullptr;

	std::strtof(literal.c_str(), &end);
	return (end == literal.c_str() + literal.size() - 1);
}

bool ScalarConverter::representsDouble(const std::string& literal) {
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return (true);

	char	*end = nullptr;

	std::strtod(literal.c_str(), &end);
	return (*end == '\0');
}

void ScalarConverter::convertFromChar(char c)
{
	std::cout	<< "char: '" << c << "'\n"
				<< "int: " << static_cast<int>(c) << "\n"
				<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n"
				<< "double: " << static_cast<double>(c) << "\n";
}

void ScalarConverter::convertFromInt(int i)
{
	if (!std::isprint(i))
		std::cout << "char: not displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(i) << "'\n";

	std::cout	<< "int: " << i << '\n'
				<< "float: " << static_cast<float>(i) << "f\n"
			 	<< "double: " << static_cast<double>(i) << '\n';
}

void ScalarConverter::convertFromFloat(float f)
{
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
		std::cout << "char: out of range\n";
	else if (!std::isprint(static_cast<int>(f)))
		std::cout << "char: not displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(f) << "'\n";

	if (std::isnan(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "int: out of range\n";
	else
		std::cout << "int: " << static_cast<int>(f) << '\n';

	std::cout	<< "float: " << f << "f\n"
				<< "double: " << static_cast<double>(f) << '\n';
}

void ScalarConverter::convertFromDouble(double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: out of range\n";
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: not displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";

	if (std::isnan(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: out of range\n";
	else
		std::cout << "int: " << static_cast<int>(d) << '\n';

	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "float: out of range\n";
	else
		std::cout << "float: " << static_cast<float>(d) << "f\n";

	std::cout << "double: " << d << '\n';
}
