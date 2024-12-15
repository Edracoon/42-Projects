#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap( void ) // default
{
	std::cout << "FragTrap Default Constructor" << std::endl;
	this->_AttackDmg = 30;
	this->_EnergyPoints = 100;
	this->_HitPoins = 100;
}

FragTrap::FragTrap( std::string name ) // parameter
{
	std::cout << "FragTrap Parameter Constructor" << std::endl;
	this->setName(name);
	this->_AttackDmg = 30;
	this->_EnergyPoints = 100;
	this->_HitPoins = 100;
}

FragTrap::FragTrap( FragTrap const & rhs ) // copy
{
	std::cout << "FragTrap Copy Constructor" << std::endl;
	*this = rhs;
}

FragTrap::~FragTrap( void ) // destructor
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

//	======== Actions =========

void	FragTrap::attack(std::string const & target)
{
	std::cout << "FragTrap " << this->getName() << " attacks " << target
			 << " causing " << this->getAttDmg() << " points of damage!" << std::endl;
}

void	FragTrap::takeDamage( unsigned int amount )
{
	std::cout << "FragTrap " << this->getName() << " is attacked : -" <<
		amount << " HP !" << std::endl;
}

void	FragTrap::beRepaired( unsigned int amount )
{
	std::cout << "FragTrap " << this->getName() << " use healing potion : " << amount << " HP";
	std::cout << " ... Healing done." << std::endl;
}

//	======== Specific =========

void	FragTrap::highFivesGuys( void )
{
	std::string request;

	std::cout << "FragTrap " << this->getName() << " is asking for a high fives" << std::endl;
	std::cout << "Yes/No : ";
	std::getline(std::cin, request);
	if (request == "Yes" || request == "yes" || request == "y")
		std::cout << "FragTrap " << this->getName() << " High Fives ! *clap*" << std::endl;
	else
		std::cout << "FlagTrap " << this->getName() << " : *Sad noises*" << std::endl;
}

std::string	FragTrap::getName() const {
	return (this->_name);
}

int		FragTrap::getHP() const {
	return (this->_HitPoins);
}

int		FragTrap::getEP() const {
	return (this->_EnergyPoints);
}

int		FragTrap::getAttDmg() const {
	return (this->_AttackDmg);
}