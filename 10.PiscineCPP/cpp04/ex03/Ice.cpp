#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice( void )
{
	std::cout << "Ice Default constructor" << std::endl;
	this->type = "ice";
}

Ice::Ice( std::string type )
{
	std::cout << "Ice Parameter constructor" << std::endl;
	this->type = type;
}

Ice::Ice( Ice const & rhs )
{
	std::cout << "Ice Copy constructor" << std::endl;
	*this = rhs;
}

Ice::~Ice( void )
{
	std::cout << "Ice Default destructor" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria*	temp = new Ice("ice");
	return (temp);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice&	Ice::operator=(Ice const & rhs)
{
	this->type = rhs.type;
	return (*this);
}