#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
			Ice( void );
			Ice( std::string type );
			Ice( Ice const & rhs );
			~Ice( void );

			virtual AMateria* clone() const;
			virtual void use(ICharacter& target);

			Ice&	operator=(Ice const & rhs);
};

#endif