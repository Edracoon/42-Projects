#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "======= Constructors =======" << std::endl;
	ClapTrap	Human("Aurelien");
	ClapTrap	CopyHuman(Human);
	ClapTrap	Elf("Sarah");
	ClapTrap	Ork;
	Ork.setName("Ork");

	std::cout << "======= Actions =======" << std::endl;
	Human.attack("Ork");
	Ork.takeDamage(Human.getAttDmg());
	Ork.beRepaired(5);
	Elf.attack("Aurelien");
	std::cout << "====== Destructors ======" << std::endl;
}