#include "Bucket.hpp"

template<Buckable Unit>
Bucket<Unit>::Bucket()
	:	_total(0)
	,	_count(0)
{}

template<Buckable Unit>
Bucket<Unit>::Bucket(Bucket<Unit> const &other)
	:	_total(other._total)
	,	_count(other._count)
{}

template<Buckable Unit>
Bucket<Unit> &
Bucket<Unit>::operator=(Bucket<Unit> const &other)
{
	if (this != &other) {
		_count = other._count;
		_total = other._total;
	}
	return (*this);
}

template<Buckable Unit>
void
Bucket<Unit>::add(Unit value)
{
	_total += value;
	++_count;
}

template<Buckable Unit>
Unit
Bucket<Unit>::average()
const {
	return ((_count == 0) ? Unit{0} : _total / _count);
}
