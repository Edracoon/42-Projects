#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	private:
			std::string type;
	public:
			Weapon();
			Weapon(std::string name);
			~Weapon();
			std::string const & getType();
			void	setType(std::string str);
};

#endif