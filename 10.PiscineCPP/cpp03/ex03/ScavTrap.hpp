#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	private:
			unsigned int	_HitPoins;
			unsigned int	_EnergyPoints;
			unsigned int	_AttackDmg;
	public:
			// === Constructor / Destructor ===
			ScavTrap( void );
			ScavTrap( std::string name );
			ScavTrap( ScavTrap const & rhs);
			~ScavTrap( void );

			// === Set / Get ===
			std::string	getName() const;
			int			getHP() const;
			int			getEP() const;
			int			getAttDmg() const;

			// ==== Actions ====
			void	attack(std::string const & target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);

			void	guardGate();
};

#endif