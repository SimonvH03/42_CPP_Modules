#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <iomanip>

class Fixed
{
	private:
		static const int	fractionalBits = 8;
		int					raw;

	public:
		Fixed();
		Fixed(int const iValue);
		Fixed(float const fValue);
		Fixed(Fixed const &src);
		Fixed& operator=(Fixed const &src);
		~Fixed();

		void	setRawBits(int const raw);
		void	setRawBits(float const raw);

		int		getRawBits() const;
		int		toInt() const;
		float	toFloat() const;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif
