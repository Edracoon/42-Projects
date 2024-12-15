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

Fixed::Fixed( const int n )
{
	std::cout << "Int constructor called" << std::endl;
	this->_pf = n << this->_bf;
}

Fixed::Fixed( const float n )
{
	std::cout << "Float constructor called" << std::endl;
	this->_pf = roundf(n * (1 << this->_bf));
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
	return (this->_pf);
}

// =============================
//= CONVERTER PF TO INT / FLOAT =
// =============================

int	Fixed::toInt( void ) const
{
	return (this->_pf >> this->_bf);
}

float	Fixed::toFloat( void ) const
{
	return (((double)this->_pf / (double)(1 << this->_bf)));
}

// =============================
// ====== PRINT OPERATOR =======
// =============================

std::ostream&	operator<<(std::ostream& ifs, Fixed const & rhs )
{
	std::cout << rhs.toFloat();
	return (ifs);
}