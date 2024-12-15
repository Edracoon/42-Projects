#include <iostream>
#include "iter.hpp"
#include <unistd.h>

template< typename T >
void	print_elem( T elem )
{
	std::cout << elem << std::endl;
}

template< typename T >
void	add_ten_print( T elem )
{
	elem += 10;
	std::cout << elem << std::endl;
}

void	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	std::cout << c;
}

int	main(void)
{
	int				tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string		strs[] = { "Coucou", "Comment" , "Vas", "-Tu", "?"};
	char*			cstr = strdup("Bonsoir");

	std::cout << std::endl;
	std::cout << "print_elem sur chaque element de l'array : " << std::endl;
	iter(tab, 10, print_elem);

	std::cout << std::endl;
	std::cout << "add_ten_print sur chaque element de l'array et afficher le resultat: " << std::endl;
	iter(tab, 10, add_ten_print);

	std::cout << std::endl;
	std::cout << "print_elem sur chaque str de mon array de string :" << std::endl;
	iter(strs, 5, print_elem);

	std::cout << std::endl;
	std::cout << "ft_toupper sur chaque char de cstr" << std::endl;
	iter(cstr, 7, ft_toupper);
	
	std::cout << std::endl;
	return (0);
}
