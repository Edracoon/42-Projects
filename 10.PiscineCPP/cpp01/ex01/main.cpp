#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	int nb = 7;

	Zombie* Horde = zombieHorde(nb, "Florent");

	for (int i = 0 ; i < nb ; i++)
		Horde[i].announce();

	delete [] Horde;
}
