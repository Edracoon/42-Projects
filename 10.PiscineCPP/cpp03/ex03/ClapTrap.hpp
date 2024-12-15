#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
			// ==== Stats ====
			std::string		_name;
			unsigned int	_HitPoins;
			unsigned int	_EnergyPoints;
			unsigned int	_AttackDmg;
	public:
			// === Constructor / Destructor ===
			ClapTrap( void );
			ClapTrap( std::string name );
			ClapTrap( ClapTrap const & rhs);
			~ClapTrap( void );

			// ==== Operators ====
			ClapTrap&	operator=( ClapTrap const & rhs);

			// ==== Actions ====
			void	attack(std::string const & target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);

			// ==== Set / Get =====
			std::string		getName( void ) const;
			void			setName(std::string name);
			unsigned int	getAttDmg( void ) const ;
			void			setAttdmg( unsigned int dmg );
			unsigned int	getHP( void ) const ;
			void			setHP( unsigned int hp );
			unsigned int	getEP( void ) const ;
			void			setEP( unsigned int ep );
};

std::ostream&	operator<<(std::ostream& ofs, ClapTrap const & rhs);

#endif