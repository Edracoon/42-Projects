#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
			Cure( void );
			Cure( std::string type );
			Cure( Cure const & rhs );
			~Cure( void );

			virtual AMateria* clone() const;
			virtual void use(ICharacter& target);

			Cure&	operator=(Cure const & rhs);
};

#endif