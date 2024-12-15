#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
			// === Constructor / Destructor ===
			ScavTrap( void );
			ScavTrap( std::string name );
			ScavTrap( ScavTrap const & rhs);
			~ScavTrap( void );

			// ==== Actions ====
			void	attack(std::string const & target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);

			void	guardGate();
};

#endif