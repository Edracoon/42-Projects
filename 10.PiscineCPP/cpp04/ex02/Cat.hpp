#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
			Brain*	brain;
	public:
			// ==== Canon ====
			Cat( void );
			Cat( std::string type );
			Cat( Cat const & rhs );
			virtual ~Cat( void );

			void		setType(std::string type);
			std::string	getType() const;
			
			// === method ===
			void		makeSound( void ) const ;

			Cat&		operator=(Cat const & rhs);
};

#endif