#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <iomanip>

class Fixed
{
	private:
		static const int	fractionalBits = 8;
		int					raw;

		void	announce(std::string const &name, std::string const &func) const;

	public:
		Fixed();
		Fixed(int const iValue);
		Fixed(float const fValue);
		Fixed(Fixed const &src);
		Fixed& operator=(Fixed const &src);
		~Fixed();

		float	toFloat() const;
		int		toInt() const;

		void	setRawBits(int const raw);
		void	setRawBits(float const raw);
		int		getRawBits() const;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif
