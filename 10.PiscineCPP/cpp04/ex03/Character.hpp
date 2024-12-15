#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
			std::string		_name;
			AMateria*		Materia[4];
			int				index;
	public:
		Character( void );
		Character( std::string name );
		Character( Character const & rhs );
		~Character( void );

		virtual std::string const & getName() const;
		AMateria*	const &	getMateria(int i) const;
		virtual void		equip(AMateria* m);
		virtual void		unequip(int idx);
		virtual void		use(int idx, ICharacter& target);

		Character&	operator=(Character const & rhs);
};

#endif