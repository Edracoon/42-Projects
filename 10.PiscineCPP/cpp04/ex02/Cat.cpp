#include "Cat.hpp"

// ==== Constructors ====
Cat::Cat( void )
{
	std::cout << "Default Cat Constructor" << std::endl;
	this->brain = new Brain();
}

Cat::Cat( std::string type )
{
	std::cout << "Parameter Cat Constructor" << std::endl;
	this->setType(type);
	this->brain = new Brain();
}

Cat::Cat( Cat const & rhs )
{
	std::cout << "Copy Cat Constructor" << std::endl;
	*this = rhs;
}

Cat::~Cat( void )
{
	delete this->brain;
	std::cout << "Destructor Cat" << std::endl;
}

// === Method ===
void	Cat::makeSound( void ) const 
{
	std::cout << "The Cat is meowing" << std::endl;
}

// === Set / Get === 
void		Cat::setType(std::string type) {
	this->type = type;
}

std::string	Cat::getType() const {
	return (this->type);
}

Cat&		Cat::operator=(Cat const & rhs)
{
	this->brain = new Brain(*(rhs.brain));
	this->setType(rhs.getType());
	return (*this);
}
