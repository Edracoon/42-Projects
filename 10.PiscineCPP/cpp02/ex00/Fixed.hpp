#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
			int					_pf;
			static const int	_bf = 8;
	public:
			Fixed( void );
			Fixed( Fixed const & rhs );
			~Fixed( void );

			Fixed&	operator=(Fixed const & rhs);

			int		getRawBits( void ) const;
			void	setRawBits( int const raw );
};

#endif
