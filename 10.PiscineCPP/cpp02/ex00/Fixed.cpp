#include "Fixed.hpp"

// =============================
// ======== CONSTRUCTORS =======
// =============================

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_pf = 0;
}

Fixed::Fixed( Fixed const & rhs )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

// =============================
// ======== DESTRUCTOR =========
// =============================

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

// ==============================
// ==== ASSIGNATION OPERATOR ====
// ==============================

Fixed&	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	this->_pf = rhs.getRawBits();
	return (*this);
}

// =============================
// ==== SET / GET FUNCTIONS ====
// =============================

void	Fixed::setRawBits( int const raw )
{
	this->_pf = raw;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_pf);
}