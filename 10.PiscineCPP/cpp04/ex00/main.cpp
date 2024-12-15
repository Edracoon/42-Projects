#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "====== Tests ======" << std::endl;
	
	const Animal* Ani		= new Animal("Kevin");
	const Animal* Doggo 	= new Dog("Florent");
	const Animal* Catti		= new Cat("Micka");

	std::cout << Ani->getType() << " " << std::endl;
	std::cout << Doggo->getType() << " " << std::endl;
	std::cout << Catti->getType() << " " << std::endl;

	Catti->makeSound(); 	// Cat sound
	Doggo->makeSound(); 	// Dog sound
	Ani->makeSound();		// Animal Sound
	const Animal* test = new Animal(*Ani);
	test->makeSound();
	std::cout << "====== Wrong Test =====" << std::endl;
	
	const WrongAnimal* wAni	= new WrongAnimal();
	const WrongAnimal* wCat	= new WrongCat();

	wAni->makeSound();		// Wrong Animal Sound;
	wCat->makeSound();		// Wrong Cat Sound -> Animal Sound;

	delete wAni;
	delete wCat;

	delete Ani;
	delete Doggo;
	delete Catti;
}
