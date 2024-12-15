#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);

	// delete bob;
	// delete me;
	// delete src;

	// AMateria*	test = new Ice();
	// std::cout << "======" << std::endl;
	// AMateria* test1 = test->clone();
	// std::cout << "======" << std::endl;
	// std::cout << test1->getType() << std::endl;
	// std::cout << "======" << std::endl;
	// delete test;
	// delete test1;

	std::cout << "=============" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete	me;
	delete	bob;
	delete	src;
	std::cout << "=============" << std::endl;

	return (0);
}
