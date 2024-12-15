#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
			std::string		_name;
			unsigned int	_HitPoins;
			unsigned int	_EnergyPoints;
			unsigned int	_AttackDmg;
	public:
			// === Constructor / Destructor ===
			DiamondTrap( void );
			DiamondTrap( std::string name );
			DiamondTrap( DiamondTrap const & rhs );
			~DiamondTrap( void );

			// === set / get ===
			void		setName(std::string name);
			std::string	getName() const;
			int			getHP() const;
			int			getEP() const;
			int			getAttDmg() const;

			void	attack(std::string const & target);

			void	whoAmI( void );
			void	guardGate( void );
			void	highFivesGuys( void );

};

std::ostream&	operator<<(std::ostream& ofs, DiamondTrap const & rhs);

#endif
