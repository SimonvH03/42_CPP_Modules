#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <iomanip>
#include <cmath>

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
		Fixed&	operator=(Fixed const &src);
		~Fixed();

		bool	operator>(Fixed const &num) const;
		bool	operator<(Fixed const &num) const;
		bool	operator>=(Fixed const &num) const;
		bool	operator<=(Fixed const &num) const;
		bool	operator==(Fixed const &num) const;
		bool	operator!=(Fixed const &num) const;
		Fixed	operator+(Fixed const &num) const;
		Fixed	operator-(Fixed const &num) const;
		Fixed	operator*(Fixed const &num) const;
		Fixed	operator/(Fixed const &num) const;
		Fixed&	operator+=(Fixed const &num);
		Fixed&	operator-=(Fixed const &num);
		Fixed&	operator*=(Fixed const &num);
		Fixed&	operator/=(Fixed const &num);
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		float	toFloat() const;
		int		toInt() const;

		void	setRawBits(int const raw);
		void	setRawBits(float const raw);
		int		getRawBits() const;

		static Fixed&		min(Fixed &a, Fixed &b);
		static Fixed const&	min(Fixed const &a, Fixed const &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static Fixed const&	max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif
