#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure( void )
{
	std::cout << "Cure Default constructor" << std::endl;
	this->type = "cure";
}

Cure::Cure( std::string type )
{
	std::cout << "Cure Parameter constructor" << std::endl;
	this->type = type;
}

Cure::Cure( Cure const & rhs )
{
	std::cout << "Cure Copy constructor" << std::endl;
	*this = rhs;
}

Cure::~Cure( void )
{
	std::cout << "Cure Default destructor" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria*	temp = new Cure("cure");
	return (temp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure&	Cure::operator=(Cure const & rhs)
{
	this->type = rhs.type;
	return (*this);
}
