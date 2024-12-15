#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria( void )
{
	std::cout << "AMateria Default constructor" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria Parameter constructor" << std::endl;
	this->type = type;
}

AMateria::AMateria( AMateria const & rhs )
{
	std::cout << "AMateria Copy constructor" << std::endl;
	*this = rhs;
}

AMateria::~AMateria( void )
{
	std::cout << "AMateria Virtual Destructor" << std::endl;
}

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "virtual : * shoots an ice bolt at " << target.getName() << " *" << std::endl;
	std::cout << "virtual : * heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria&	AMateria::operator=(AMateria const & rhs)
{
	this->type = rhs.type;
	return (*this);
}