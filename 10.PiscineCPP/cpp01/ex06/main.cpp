#include <iostream>
#include "Karen.hpp"

int	main(int ac, char **av)
{
	if (ac == 2 && av[1])
	{
		std::string	level(av[1]);
		Karen		karen;
		if (level.empty())
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		karen.complain(level);
	}
	else
		std::cout << "Error: Numbers of arguments" << std::endl;
	return (0);
}