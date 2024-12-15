#include "Dog.hpp"

// ==== Constructors ====
Dog::Dog( void )
{
	std::cout << "Default Dog Constructor" << std::endl;
}

Dog::Dog( std::string type )
{
	std::cout << "Parameter Dog Constructor" << std::endl;
	this->setType(type);
}

Dog::Dog( Dog const & rhs )
{
	std::cout << "Copy Dog Constructor" << std::endl;
	*this = rhs;
}

Dog::~Dog( void )
{
	std::cout << "Destructor Dog" << std::endl;
}

// === Method ===
void	Dog::makeSound( void ) const
{
	std::cout << "The Dog is barking" << std::endl;
}

// === set / get === 
void		Dog::setType(std::string type) {
	this->type = type;
}

std::string	Dog::getType() const {
	return (this->type);
}

Dog&	Dog::operator=(Dog const & rhs)
{
	this->setType(rhs.getType());
	return (*this);
}