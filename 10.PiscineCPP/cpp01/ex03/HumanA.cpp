#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name)
{
	std::cout << "Creating HumanA : '" << name << 
				"' Weapon : '" <<  weapon.getType() << "'" << 
				std::endl;
}

HumanA::~HumanA()
{
	;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}
