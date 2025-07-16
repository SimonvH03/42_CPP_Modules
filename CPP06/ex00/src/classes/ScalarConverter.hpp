#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &original);
		ScalarConverter &operator=(ScalarConverter const &original);
		~ScalarConverter();

		static char		convertToChar(const std::string &string);
		static int		convertToInt(const std::string &string);
		static float	convertToFloat(const std::string &string);
		static double	convertToDouble(const std::string &string);

	public:
		static int	convert(const std::string &string);

	private:
		class RangeException : public std::exception
		{
			private:
				std::string _message;
			public:
				RangeException(const std::string& message);
				const char* what() const throw();
		};
};

#endif
