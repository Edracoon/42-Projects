#include "Fixed.hpp"

// =============================
// ======== CONSTRUCTORS =======
// =============================

Fixed::Fixed( void )
{
	// std::cout << "Default constructor called" << std::endl;
	this->_pf = 0;
}

Fixed::Fixed( Fixed const & rhs )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::Fixed( const int n )
{
	// std::cout << "Int constructor called" << std::endl;
	this->_pf = n << this->_bf;
}

Fixed::Fixed( const float n )
{
	// std::cout << "Float constructor called" << std::endl;
	this->_pf = roundf(n * (1 << this->_bf));
}

// =============================
// ======== DESTRUCTOR =========
// =============================

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
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
// ===== MAX / MIN STATIC ======
// =============================

Fixed	Fixed::max( Fixed & lhs, Fixed & rhs )
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed	Fixed::min( Fixed & lhs, Fixed & rhs )
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed	Fixed::max( const Fixed & lhs, const Fixed & rhs )
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed	Fixed::min( const Fixed & lhs, const Fixed & rhs )
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}
