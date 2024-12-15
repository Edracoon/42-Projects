#include "Brain.hpp"

// === Constructors ===

Brain::Brain( void )
{
	std::cout << "Default Brain Constructor" << std::endl;
}

Brain::Brain( std::string idea )
{
	std::cout << "Parameter Brain Constructor" << std::endl;
	this->ideas[0] = idea;
}

Brain::Brain( Brain const & rhs )
{
	std::cout << "Copy Brain Constructor" << std::endl;
	*this = rhs;
}

Brain::~Brain( void )
{
	std::cout << "Destructor Brain" << std::endl;
}

// === Operator ===

Brain&		Brain::operator=(Brain const & rhs)
{
	for (int i = 0 ; i < 100 ; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}
