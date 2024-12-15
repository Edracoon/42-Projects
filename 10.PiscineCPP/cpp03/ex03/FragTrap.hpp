#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public virtual ClapTrap
{
	private:
			unsigned int	_HitPoins;
			unsigned int	_EnergyPoints;
			unsigned int	_AttackDmg;
	public:
			// === Constructor / Destructor ===
			FragTrap( void );
			FragTrap( std::string name );
			FragTrap( FragTrap const & rhs);
			~FragTrap( void );

			// === Get ===
			std::string	getName() const;
			int			getHP() const;
			int			getEP() const;
			int			getAttDmg() const;

			// ==== Actions ====
			void	attack( std::string const & target );
			void	takeDamage( unsigned int amount );
			void	beRepaired( unsigned int amount );

			void	highFivesGuys( void );
};

#endif
