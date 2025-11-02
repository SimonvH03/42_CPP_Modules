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
		Fixed(Fixed const &src);
		Fixed& operator=(Fixed const &src);
		~Fixed();

		void	setRawBits(int const asInt);
		int		getRawBits() const;
};

#endif
