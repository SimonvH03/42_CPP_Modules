#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>
# include <cmath>
# include <cstdlib>
# include <cctype>

class ScalarConverter
{
	public:
		static void	convert(const std::string &input);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &original);
		ScalarConverter &operator=(ScalarConverter const &original);
		~ScalarConverter();

		static bool	representsChar(const std::string &input);
		static bool	representsInt(const std::string &input);
		static bool	representsFloat(const std::string &input);
		static bool	representsDouble(const std::string &input);

		static void	convertFromChar(char c);
		static void	convertFromInt(int i);
		static void	convertFromFloat(float f);
		static void	convertFromDouble(double d);
};

#endif
