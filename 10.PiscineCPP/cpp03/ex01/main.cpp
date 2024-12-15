#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	// std::cout << "======= Constructors =======" << std::endl;
	// ClapTrap	Human("Aurelien");
	// ClapTrap	CopyHuman(Human);
	// ClapTrap	Elf("Sarah");
	// ClapTrap	Ork;
	// Ork.setName("Ork");

	// std::cout << "======= Actions =======" << std::endl;
	// Human.attack("Ork");
	// Ork.takeDamage(Human.getAttDmg());
	// Ork.beRepaired(5);
	// Elf.attack("Aurelien");
	// std::cout << "====== Destructors ======" << std::endl;

	std::cout << "======= ScavTrap Tester =====" << std::endl;
	ScavTrap	Scavi;
	Scavi.setName("Jean");

	ScavTrap	Scavo("Michel");

	// Actions
	Scavo.attack("Jean");
	Scavi.takeDamage(Scavo.getAttDmg());
	Scavi.beRepaired(50);
	Scavi.guardGate();
}
