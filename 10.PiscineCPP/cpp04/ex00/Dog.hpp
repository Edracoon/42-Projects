#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
			// ==== Canon ====
			Dog( void );
			Dog( std::string type );
			Dog( Dog const & rhs );
			~Dog( void );

			void		setType(std::string type);
			std::string	getType()const;
		
			// === method ===
			virtual void	makeSound( void ) const ;

			Dog&	operator=(Dog const & rhs);
};

#endif