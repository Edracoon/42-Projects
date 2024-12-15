#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) // default
{
	std::cout << "ScavTrap Default Constructor" << std::endl;
	this->setAttdmg(20);
	this->setEP(50);
	this->setHP(100);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) // parameter
{
	std::cout << "ScavTrap Parameter Constructor" << std::endl;
	this->setName(name);
	this->setAttdmg(20);
	this->setEP(50);
	this->setHP(100);
}

ScavTrap::ScavTrap( ScavTrap const & rhs ) // copy
{
	std::cout << "ScavTrap Copy Constructor" << std::endl;
	*this = rhs;
}

void	ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << this->getName() << " attacks " << target
			 << " causing " << this->getAttDmg() << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage( unsigned int amount )
{
	std::cout << "ScavTrap " << this->getName() << " is attacked : -" <<
		amount << " HP !" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << this->getName() << " use healing potion : " << amount << " HP";
	std::cout << " ... Healing done." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " has enterred in Gate Keeper mode." << std::endl;
}
