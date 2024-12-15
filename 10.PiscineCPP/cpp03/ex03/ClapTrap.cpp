#include "ClapTrap.hpp"

// =======================
// ==== CONSTRUCTORS =====
// =======================

ClapTrap::ClapTrap( void ) // ==== Default
{
	std::cout << "ClapTrap Default constructor" << std::endl;
	this->_HitPoins = 10;
	this->_EnergyPoints = 10;
	this->setAttdmg(0);
	return ;
}

ClapTrap::ClapTrap( std::string name ) // ==== Parameter
{
	std::cout << "ClapTrap Parameter constructor : " << name << std::endl;
	this->_name = name;
	this->_HitPoins = 10;
	this->_EnergyPoints = 10;
	this->setAttdmg(0);
}

ClapTrap::ClapTrap( ClapTrap const & rhs ) // ==== Copy
{
	std::cout << "ClapTrap Copy constructor : " << rhs._name << std::endl;
	*this = rhs;
}
// =======================
// ===== DESTRUCTOR ======
// =======================

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

// =======================
// ====== SET / GET ======
// =======================

void	ClapTrap::setName(std::string name) {
	std::cout << "setName = " << name << std::endl;
	this->_name = name;
}

std::string	ClapTrap::getName( void ) const {
	return (this->_name);
}

unsigned int	ClapTrap::getAttDmg( void ) const {
	return (this->_AttackDmg);
}

void		ClapTrap::setAttdmg( unsigned int dmg ) {
	this->_AttackDmg = dmg;
}

unsigned int	ClapTrap::getHP( void ) const {
	return (this->_HitPoins);
}

void			ClapTrap::setHP( unsigned int hp ) {
	this->_HitPoins = hp;
}

unsigned int	ClapTrap::getEP( void ) const {
	return (this->_EnergyPoints);
}

void			ClapTrap::setEP( unsigned int ep ) {
	this->_EnergyPoints = ep;
}

// =======================
// ======= Actions =======
// =======================

void	ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << this->getName() << " attacks " << target
		<< " causing " << this->_AttackDmg << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " << this->getName() << " is attacked : -" <<
		amount << " HP !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName() << " use healing potion : " << amount << " HP";
	std::cout << " ... Healing done." << std::endl;
}

// =======================
// ===== Operators =======
// =======================

ClapTrap&	ClapTrap::operator=( ClapTrap const & rhs)
{
	this->setName(rhs.getName());
	this->_HitPoins = rhs.getHP();
	this->_EnergyPoints = rhs.getEP();
	this->_AttackDmg = rhs.getAttDmg();
	return (*this);
}

std::ostream&	operator<<(std::ostream& ofs, ClapTrap const & rhs)
{
	std::cout << rhs.getName();
	return (ofs);
}
