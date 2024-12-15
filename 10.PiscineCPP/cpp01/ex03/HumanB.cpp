#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : weapon(NULL), name(name)
{
	std::cout << "Creating HumanB : '" << name << "'" << 
				std::endl;
}

HumanB::~HumanB()
{
	;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}