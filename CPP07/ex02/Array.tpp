#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <stdexcept>

template<typename T>
Array<T>::Array()
	:	_size(0),
		_data(new T[_size])
{
	std::cout << "Array Default Constructor\n";
}

template<typename T>
Array<T>::Array(unsigned int n)
	:	_size(n),
		_data(new T[_size])
{
	std::cout << "Array Size Constructor\n";
}

template<typename T>
Array<T>::Array(Array const &original)
	:	_size(original._size),
		_data(new T[_size])
{
	std::cout << "Array Copy Constructor\n";
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = original[i];
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &original)
{
	std::cout << "Array Assignment Operator\n";
	if (this != &original)
	{
		delete[] _data;
		_size = original._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = original[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Array Destructor\n";
	delete[] _data;
}

template<typename T>
T &Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw std::out_of_range("index out of range");
	return (_data[n]);
}

template<typename T>
T const &Array<T>::operator[](unsigned int n)
const
{
	if (n >= _size)
		throw std::out_of_range("index out of range");
	return (_data[n]);
}

template<typename T>
unsigned int	Array<T>::size()
const
{
	return (_size);
}

#endif
