#include "WrongCat.hpp"

// ==== Constructors ====
WrongCat::WrongCat( void )
{
	std::cout << "Default WrongCat Constructor" << std::endl;
}

WrongCat::WrongCat( std::string type )
{
	std::cout << "Parameter WrongCat Constructor" << std::endl;
	this->setType(type);
}

WrongCat::WrongCat( WrongCat const & rhs )
{
	std::cout << "Copy WrongCat Constructor" << std::endl;
	*this = rhs;
}

WrongCat::~WrongCat( void )
{
	std::cout << "Destructor WrongCat" << std::endl;
}

// === Method ===
void	WrongCat::makeSound( void ) const 
{
	std::cout << "The WrongCat is meowing" << std::endl;
}

// === set / get === 
void		WrongCat::setType(std::string type) {
	this->type = type;
}

std::string	WrongCat::getType() const {
	return (this->type);
}

WrongCat&			WrongCat::operator=(WrongCat const & rhs)
{
	this->setType(rhs.getType());
	return (*this);
}