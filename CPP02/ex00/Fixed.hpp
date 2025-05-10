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
		Fixed(Fixed const &src);
		Fixed& operator=(Fixed const &src);
		~Fixed();

		void	setRawBits(int const raw);
		int		getRawBits() const;
};

#endif
