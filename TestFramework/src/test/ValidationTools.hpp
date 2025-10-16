#ifndef VALIDATIONTOOLS_HPP
# define VALIDATIONTOOLS_HPP
# include <stdexcept>
# include <source_location>
# include <sstream>

class	validationToolsException : public std::exception
{
	public:
		validationToolsException(
			std::source_location const &location = std::source_location::current(),
			std::string const &message = "No apparent reason...")
			:	_message(formatLocation(location) + message) {}

		const char *what() const throw() override {
			return (_message.c_str());
		}

	private:
		std::string	_message;

		std::string	formatLocation(std::source_location const &location) {
			return (static_cast<std::string>("(") + location.file_name() + ":" + std::to_string(location.line()) + ") ");
		}
};

inline void	check(
	std::string const &expression, bool result,
	std::source_location const &location = std::source_location::current())
{
	if (!result) throw validationToolsException(location,
		"Check failed: (" + expression + ") is false");
}
# define CHECK(expr) check(#expr, (expr))

template <typename A, typename B>
	requires std::equality_comparable_with<A, B>
void	equate(
	std::string	const &aStr,
	std::string const &bStr,
	A const &a,
	B const &b,
	std::source_location const &location = std::source_location::current())
{
	if (a != b) throw validationToolsException(location,
		"Equation failed: " + aStr + " != " + bStr);
}
# define EQUATE(a, b) equate(#a, #b, a, b)

#endif
