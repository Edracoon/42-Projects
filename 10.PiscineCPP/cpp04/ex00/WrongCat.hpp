#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
			// ==== Canon ====
			WrongCat( void );
			WrongCat( std::string type );
			WrongCat( WrongCat const & rhs );
			~WrongCat( void );

			void		setType(std::string type);
			std::string	getType() const;
			
			// === method ===
			void	makeSound( void ) const ;
			WrongCat&	operator=(WrongCat const & rhs);
};

#endif