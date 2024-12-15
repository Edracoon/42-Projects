#include "Fixed.hpp"

// =============================
// ====== PRINT OPERATOR =======
// =============================

std::ostream&	operator<<(std::ostream& ifs, Fixed const & rhs )
{
	std::cout << rhs.toFloat();
	return (ifs);
}

// ==============================
// ==== ASSIGNATION OPERATOR ==== 
// ==============================

Fixed&	Fixed::operator=( Fixed const & rhs )
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_pf = rhs.getRawBits();
	return (*this);
}

// =================================
// ==== INCREMENTATION OPERATOR ====
// =================================

Fixed&	Fixed::operator++( void )
{
	this->_pf++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed temp(*this);

	operator++();
	return (temp);
}
// =================================
// ==== DECREMENTATION OPERATOR ====
// =================================

Fixed&	Fixed::operator--( void )
{
	this->_pf--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed temp(*this);

	operator--();
	return (temp);
}

// =============================
// ======= DIFF OPERATOR =======
// =============================

bool	Fixed::operator>( const Fixed& rhs )
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<( const Fixed& rhs )
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator<=( const Fixed& rhs )
{
	return !(rhs.getRawBits() > this->getRawBits());
}

bool	Fixed::operator>=( const Fixed& rhs )
{
	return !(rhs.getRawBits() < this->getRawBits());
}

bool	Fixed::operator==( Fixed const & rhs )
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=( Fixed const & rhs )
{
	return (this->getRawBits() != rhs.getRawBits());
}

// =============================
// ==== ARITHMETIC OPERATOR ====
// =============================

Fixed	Fixed::operator+( Fixed const & rhs )
{
	Fixed temp(*this);

	temp.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (temp);
}

Fixed	Fixed::operator-( Fixed const & rhs )
{
	Fixed temp(*this);

	temp.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (temp);
}

Fixed	Fixed::operator*( Fixed const & rhs )
{
	Fixed	temp(*this);

	// std::cout << (this->getRawBits() >> 8) << " * " << (rhs.getRawBits()) << std::endl;
	temp.setRawBits((this->getRawBits() >> temp._bf ) * rhs.getRawBits());

	return (temp);
}

Fixed	Fixed::operator/( Fixed const & rhs )
{
	Fixed	temp(*this);

	// std::cout << (this->getRawBits() << 8 ) << " / " << (rhs.getRawBits()) << std::endl;
	temp.setRawBits((this->getRawBits() << temp._bf) / rhs.getRawBits());
	return (temp);
}
