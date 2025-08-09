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

template<typename TFrom, typename TTo>
std::string	ScalarConverter::toString(TFrom value)
{
	std::ostringstream	oss;

	oss << std::fixed << std::setprecision(1) << static_cast<TTo>(value);

	return (oss.str());
}

void	ScalarConverter::convert(const std::string &input)
{
	Output	output;

	output.charResult << "char: ";
	output.intResult << "int: ";
	output.floatResult << "float: ";
	output.doubleResult << "double: ";
	if (representsChar(input))
		convertFromChar(output, input[1]);
	else if (representsInt(input))
		try {convertFromInt(output, std::stoi(input));
		} catch (std::out_of_range const &except) {
			std::cout << "Error\n" << except.what() << std::endl;
			return ;
		}
	else if (representsFloat(input))
		try {convertFromFloat(output, std::stof(input));
		} catch (std::out_of_range const &except) {
			std::cout << "Error\n" << except.what() << std::endl;
			return ;
		}
	else if (representsDouble(input))
		try {convertFromDouble(output, std::stod(input));
		} catch (std::out_of_range const &except) {
			std::cout << "Error\n" << except.what() << std::endl;
			return ;
		}
	else
	{
		std::cout << "Error\nUnknown Format\n";
		return ;
	}
	std::cout	<< output.charResult.str()
				<< output.intResult.str()
				<< output.floatResult.str()
				<< output.doubleResult.str();
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
	long	n;

	n = std::strtol(literal.c_str(), &end, 10);
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		return (false);
	return (*end == '\0');
}

bool ScalarConverter::representsFloat(const std::string& literal)
{
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return (true);

	char	*end = nullptr;

	std::strtof(literal.c_str(), &end);
	return (*end == 'f' && end[1] == '\0');
}

bool ScalarConverter::representsDouble(const std::string& literal) {
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return (true);

	char	*end = nullptr;

	std::strtod(literal.c_str(), &end);
	return (*end == '\0');
}

void ScalarConverter::convertFromChar(Output &output, char c)
{
	output.charResult << "'" << toString<char, char>(c) << "'\n";
	output.intResult << toString<char, int>(c) << "\n";
	output.floatResult << toString<char, float>(c) << "f\n";
	output.doubleResult << toString<char, double>(c) << "\n";
}

void ScalarConverter::convertFromInt(Output &output, int i)
{
	if (i < 0 || i > 127)
		output.charResult << "impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(i)))
		output.charResult << "not displayable\n";
	else
		output.charResult << "'" << toString<int, char>(i) << "'\n";

	output.intResult << i << '\n';
	output.floatResult << toString<int, float>(i) << "f\n";
	output.doubleResult << toString<int, double>(i) << '\n';
}

void ScalarConverter::convertFromFloat(Output &output, float f)
{
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
		output.charResult << "impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(f)))
		output.charResult << "not displayable\n";
	else
		output.charResult << "'" << toString<float, char>(f) << "'\n";

	if (std::isnan(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		output.intResult << "impossible\n";
	else
		output.intResult << toString<float, int>(f) << '\n';

	output.floatResult << std::fixed << std::setprecision(1) << f << "f\n";
	output.doubleResult << toString<float, double>(f) << '\n';
}

void ScalarConverter::convertFromDouble(Output &output, double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		output.charResult << "impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(d)))
		output.charResult << "not displayable\n";
	else
		output.charResult << "'" << toString<double, char>(d) << "'\n";

	if (std::isnan(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		output.intResult << "impossible\n";
	else
		output.intResult << toString<double, int>(d) << '\n';

	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::lowest())
		output.floatResult << "impossible\n";
	else
		output.floatResult << toString<double, float>(d) << "f\n";

	output.doubleResult << std::fixed << std::setprecision(1) << d << '\n';
}
