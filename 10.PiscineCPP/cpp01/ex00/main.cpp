#include <iostream>
#include "Zombie.hpp"

Zombie* 	newZombie(std::string name);
void 		randomChump(std::string name);

int	main(void)
{
	Zombie Florent("Florent");
	Florent.announce();

	randomChump("Pascal");

	Zombie* Micka = newZombie("Micka");
	Micka->announce();

	delete Micka;

	return (0);
}
