#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
			std::string	tab[4];
			AMateria*	source[4];
			int			idx;
	public:
			MateriaSource( void );
			MateriaSource( MateriaSource const & rhs);
			~MateriaSource( void );
			virtual void learnMateria( AMateria* );
			virtual AMateria* createMateria( std::string const & type );

			MateriaSource&	operator=(MateriaSource const & rhs);
};

#endif
