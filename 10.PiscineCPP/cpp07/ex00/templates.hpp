#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

#include <iostream>

template< typename T >
void	swap(T & a, T & b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template< typename T >
T		min(T x, T y)
{
	return (y > x ? x : y);
}

template< typename T >
T		max(T x, T y)
{
	return (y < x ? x : y);
}

#endif