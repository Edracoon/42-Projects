#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
			int					_pf;		// point fixe
			static const int	_bf = 8;	// bits fractionnel
	public:
			Fixed( void );
			Fixed( Fixed const & rhs );
			~Fixed( void );

			Fixed(const int n);
			Fixed(const float n);

			Fixed&	operator=(Fixed const & rhs);

			int		toInt( void ) const;
			float	toFloat( void ) const ;

			int		getRawBits( void ) const;
			void	setRawBits( int const raw );
};

std::ostream&	operator<<(std::ostream& ifs, Fixed const & rhs );

#endif
