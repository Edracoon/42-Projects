#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	// setName(_name);
	std::cout << "One zombie of the horde is created" << std::endl;
}

Zombie::Zombie(std::string _name)
{
	setName(_name);
	std::cout << "Zombie " << _name << " was created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << getName() << " was killed" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string Zombie::getName()
{
	return(this->_name);
}

void	Zombie::announce()
{
	std::cout << "<" << getName() << ">" << " BraiiiiiiinnnzzzZ" << std::endl;
}
