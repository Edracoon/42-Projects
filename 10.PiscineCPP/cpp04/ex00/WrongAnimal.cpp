#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	std::cout << "Default WrongAnimal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type )
{
	std::cout << "Parameter WrongAnimal Constructor" << std::endl;
	this->setType(type);
}

WrongAnimal::WrongAnimal( WrongAnimal const & rhs )
{
	std::cout << "Copy WrongAnimal Constructor" << std::endl;
	*this = rhs;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "Destructor WrongAnimal" << std::endl;
}

// === Set / Get ===
void		WrongAnimal::setType(std::string type) {
	this->type = type;
}

std::string	WrongAnimal::getType()const {
	return (this->type);
}

// === Method ===
void	WrongAnimal::makeSound() const
{
	std::cout << "A WrongAnimal is making a sound" << std::endl;
}

WrongAnimal&			WrongAnimal::operator=(WrongAnimal const & rhs)
{
	this->setType(rhs.getType());
	return (*this);
}