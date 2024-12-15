#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
			std::string	_name;
	public:
			Zombie();
			Zombie(std::string _name);
			~Zombie();
			void 		announce( void );
			void		setName(std::string name);
			std::string	getName();
};

#endif