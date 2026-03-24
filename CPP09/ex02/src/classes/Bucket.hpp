#ifndef BUCKET_HPP
# define BUCKET_HPP
#include <concepts>

template<typename T>
concept Buckable =
requires(T a, T b, size_t n) {
	{	T{0}	};
	{	a += b	};
	{	a / n	};
};

template<Buckable Unit>
class	Bucket
{
	public:
		Bucket();
		Bucket(Bucket const &other);
		Bucket &operator=(Bucket const &other);
		~Bucket() = default;

	private:
		Unit			_total;
		unsigned int	_count;

	public:
		void	add(Unit value);
		Unit	average() const;
};

# include "Bucket.tpp"

#endif