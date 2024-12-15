#include "Character.hpp"

Character::Character( void )
{
	std::cout << "Character Default Constructor" << std::endl;
	for (int i = 0 ; i < 4 ; i++)
		this->Materia[i] = NULL;
	this->index = 0;
}

Character::Character( std::string name ) 
{
	std::cout << "Character Parameter Constructor" << std::endl;
	this->_name = name;
	for (int i = 0 ; i < 4 ; i++)
		this->Materia[i] = NULL;
	this->index = 0;
}

Character::Character( Character const & rhs )
{
	std::cout << "Character Copy Constructor" << std::endl;
	*this = rhs;
}

Character::~Character( void )
{
	for (int i = 0; i < this->index ; i++)
	{
		delete Materia[i];
	}
	std::cout << "Character Destructor" << std::endl;
}

std::string const &	Character::getName() const {
	return (this->_name);
}

AMateria*	const & Character::getMateria(int i) const {
	return(this->Materia[i]); 
}

void				Character::equip(AMateria* m) 
{
	if (this->index < 4)
	{
		if (Materia[this->index] == NULL)
			this->Materia[this->index] = m;
		this->index++;
	}
}

void				Character::unequip(int idx)
{
	if (idx < 4)
	{
		this->Materia[idx] = NULL;
		this->index = idx;
	}
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && this->Materia[idx] != NULL)
	{
		this->Materia[idx]->use(target);
	}
}

Character&	Character::operator=(Character const & rhs)
{
	this->_name = rhs.getName();
	for (int i = 0 ; i < 4 ; i++)
		this->Materia[i] = rhs.getMateria(i)->clone();
	this->index = rhs.index;
	return (*this);
}
