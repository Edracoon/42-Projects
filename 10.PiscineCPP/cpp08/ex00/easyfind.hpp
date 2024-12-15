#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>

class	ONF : public std::exception	// Exception lorsque pas d'occurence trouvée
{
	public:
			virtual const char* what() const throw () { return ("Exception: Occurence Not Found"); }
};

template< typename T >
int		easyfind(T container, int n)
{
	typename T::const_iterator	it;
	typename T::const_iterator	ite = container.end();

	for (it = container.begin() ; it != ite ; it++)
	{
		if (*it == n)
			return (*it);
	}
	throw ONF();
}

#endif