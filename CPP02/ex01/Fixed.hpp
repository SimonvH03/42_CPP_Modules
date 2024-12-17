#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <iomanip>
#include <cmath>

class Fixed
{
	private:
		static const int	bitCount = 8;
		int					value;

		void	announce(std::string const &name, std::string const &func) const;

	public:
		Fixed();
		Fixed(int const iValue);
		Fixed(float const fValue);
		Fixed(Fixed const &src);
		Fixed& operator=(Fixed const &src);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		void	setRawBits(float const raw);

		float	toFloat() const;
		int		toInt() const;
};

#endif
