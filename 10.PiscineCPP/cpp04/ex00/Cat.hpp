#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
			// ==== Canon ====
			Cat( void );
			Cat( std::string type );
			Cat( Cat const & rhs );
			~Cat( void );

			void		setType(std::string type);
			std::string	getType() const;
			
			// === method ===
			virtual void	makeSound( void ) const;

			Cat&	operator=(Cat const & rhs);
};

#endif