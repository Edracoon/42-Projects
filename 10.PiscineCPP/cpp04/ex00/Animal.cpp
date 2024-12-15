#include "Animal.hpp"

// === Constructors ===

Animal::Animal( void )
{
	std::cout << "Default Animal Constructor" << std::endl;
}

Animal::Animal( std::string type )
{
	std::cout << "Parameter Animal Constructor" << std::endl;
	this->setType(type);
}

Animal::Animal( Animal const & rhs )
{
	std::cout << "Copy Animal Constructor" << std::endl;
	*this = rhs;
}

Animal::~Animal( void )
{
	std::cout << "Destructor Animal" << std::endl;
}

void		Animal::setType(std::string type) {
	this->type = type;
}

std::string	Animal::getType() const {
	return (this->type);
}

// === Method ===
void	Animal::makeSound() const 
{
	std::cout << "An animal is making a sound" << std::endl;
}

Animal&			Animal::operator=(Animal const & rhs)
{
	this->setType(rhs.getType());
	return (*this);
}