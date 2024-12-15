#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
			int					_pf;		// valeure en point fixe
			static const int	_bf = 8;	// bits fractionnel de precision
	public:
			Fixed( void );
			Fixed( Fixed const & rhs );
			~Fixed( void );

			Fixed(const int n);
			Fixed(const float n);

			Fixed&	operator=( const Fixed & rhs );

			Fixed	operator+( Fixed const & rhs );
			Fixed	operator-( Fixed const & rhs );
			Fixed	operator*( Fixed const & rhs );
			Fixed	operator/(Fixed const & rhs);

			bool	operator>( const Fixed & rhs );
			bool	operator<( const Fixed & rhs );
			bool	operator<=( const Fixed & rhs );
			bool	operator>=( const Fixed & rhs );
			bool	operator==( const Fixed & rhs );
			bool	operator!=( Fixed const & rhs );

			Fixed&	operator++( void );
			Fixed	operator++( int );

			Fixed&	operator--( void );
			Fixed	operator--( int );

			int		toInt( void ) const;
			float	toFloat( void ) const;

			int		getRawBits( void ) const;
			void	setRawBits( int const raw );

			static Fixed	max( Fixed & lhs, Fixed & rhs );
			static Fixed	max( const Fixed & lhs, const Fixed & rhs );
			static Fixed	min( Fixed & lhs, Fixed & rhs );
			static Fixed	min( const Fixed & lhs, const Fixed & rhs );
};

std::ostream&	operator<<(std::ostream& ifs, Fixed const & rhs );

#endif
