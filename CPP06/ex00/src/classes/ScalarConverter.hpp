#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <sstream>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cmath>
# include <cstdlib>
# include <cctype>
# include <type_traits>

class ScalarConverter
{
	public:
		static void	convert(const std::string &input);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &original);
		ScalarConverter &operator=(ScalarConverter const &original);
		~ScalarConverter();

		struct Output
		{
			std::ostringstream	charResult;
			std::ostringstream	intResult;
			std::ostringstream	floatResult;
			std::ostringstream	doubleResult;
		};

		template<typename TFrom, typename TTo>
		static std::string	toString(TFrom value);

		static bool	representsDouble(const std::string &input);
		static bool	representsChar(const std::string &input);
		static bool	representsInt(const std::string &input);
		static bool	representsFloat(const std::string &input);

		static void	convertFromChar(Output &output, char c);
		static void	convertFromInt(Output &output, int i);
		static void	convertFromFloat(Output &output, float f);
		static void	convertFromDouble(Output &output, double d);
};

#endif
