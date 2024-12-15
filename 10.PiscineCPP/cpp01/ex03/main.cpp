#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	std::cout << std::endl << "==============================" << std::endl << std::endl;

	Weapon club = Weapon("Spikes Club");

	HumanA bob("Bob", club);
	club.setType("Chainsaw");
	bob.attack();

	std::cout << std::endl << "==============================" << std::endl << std::endl;

	Weapon sword = Weapon("Iron Sword");

	HumanB jim("Jim");
	jim.setWeapon(sword);
	jim.attack();
	sword.setType("Diamound Sword");
	jim.attack();

	std::cout << std::endl << "==============================" << std::endl << std::endl;
	return (0);
}
