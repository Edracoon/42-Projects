#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
			std::string type;
	public:
			// ==== Canon ====
			WrongAnimal( void );
			WrongAnimal( std::string type );
			WrongAnimal( WrongAnimal const & rhs );
			~WrongAnimal( void );

			// === Set / Get ===
			void		setType(std::string type);
			std::string	getType()const;

			// === Method ===
			void	makeSound() const ;

			WrongAnimal&			operator=(WrongAnimal const & rhs);

};

#endif