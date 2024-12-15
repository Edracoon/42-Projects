#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
											// template< typename F >
template< typename T >						// ou F f
void	iter(T* arrayptr, unsigned int length, void (f)(T))
{
	for(unsigned int i = 0 ; i < length ; i++)
	{
		f(arrayptr[i]);
	}
}

#endif
