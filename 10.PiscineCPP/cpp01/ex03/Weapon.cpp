#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon()
{
	;
}

Weapon::Weapon(std::string type)
{
	std::cout << "Creating new weapon : '" << type << "'" << std::endl;
	setType(type);
}

Weapon::~Weapon()
{
	;
}

std::string const & Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	std::cout << "setType weapon name = " << type << std::endl;
	this->type = type;
}
