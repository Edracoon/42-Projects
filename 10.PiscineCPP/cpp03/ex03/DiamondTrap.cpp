# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap() // default
{
	std::cout << "DiamondTrap Default Constructor" << std::endl;
	this->_AttackDmg = FragTrap::getAttDmg();
	this->_EnergyPoints = ScavTrap::getEP();
	this->_HitPoins = ScavTrap::getHP();
}

DiamondTrap::DiamondTrap( std::string name ) : ScavTrap(name), FragTrap(name) // parameter
{
	std::cout << "DiamondTrap Parameter Constructor" << std::endl;
	this->setName(name);
	ClapTrap::setName(name + "_clap_name");
	this->_AttackDmg = FragTrap::getAttDmg();
	this->_EnergyPoints = ScavTrap::getEP();
	this->_HitPoins = ScavTrap::getHP();
}

DiamondTrap::DiamondTrap( DiamondTrap const & rhs ) // copy
{
	std::cout << "DiamondTrap Copy Constructor" << std::endl;
	*this = rhs;
}

DiamondTrap::~DiamondTrap( void ) // destructor
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

// ====== Actions ======

void	DiamondTrap::guardGate( void )
{
	ScavTrap::guardGate();
}


void	DiamondTrap::highFivesGuys( void )
{
	FragTrap::highFivesGuys();
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "=== WhoAmI ? name = " << this->getName() << 
			" | ClapTrap name = " << ClapTrap::getName() << " ===" << std::endl;
}

// ========== set / get =============

void		DiamondTrap::setName(std::string name) {
	this->_name = name;
}

std::string	DiamondTrap::getName() const {
	return (this->_name);
}

int		DiamondTrap::getHP() const {
	return (this->_HitPoins);
}

int		DiamondTrap::getEP() const {
	return (this->_EnergyPoints);
}

int		DiamondTrap::getAttDmg() const {
	return (this->_AttackDmg);
}

// ==== Operators ====

std::ostream&	operator<<(std::ostream& ofs, DiamondTrap const & rhs)
{
	std::cout << "Name = " << rhs.DiamondTrap::getName() <<
				" | HP = " << rhs.DiamondTrap::getHP() << 
				" | EP = " << rhs.DiamondTrap::getEP() <<
				" | AttDmg = " << rhs.DiamondTrap::getAttDmg();
	return (ofs);
}
