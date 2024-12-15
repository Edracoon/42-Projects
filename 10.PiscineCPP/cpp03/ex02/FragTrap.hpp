#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap
{
	public:
			// === Constructor / Destructor ===
			FragTrap( void );
			FragTrap( std::string name );
			FragTrap( FragTrap const & rhs);
			~FragTrap( void );

			// ==== Actions ====
			void	attack( std::string const & target );
			void	takeDamage( unsigned int amount );
			void	beRepaired( unsigned int amount );

			void	highFivesGuys( void );
};

#endif
