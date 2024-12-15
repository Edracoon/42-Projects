#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
			Brain*	brain;
	public:
			// ==== Canon ====
			Dog( void );
			Dog( std::string type );
			Dog( Dog const & rhs );
			virtual ~Dog( void );

			void		setType(std::string type);
			std::string	getType()const;
		
			// === method ===
			void	makeSound( void ) const ;

			Dog&		operator=(Dog const & rhs);
};

#endif