#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);		// Random Class Creation (A, B or C)
void	identify(Base* p);	// Find and display the real type of the Base (A, B or C)
void	identify(Base& p);	// Same but without pointers

int	main(void)
{
	std::srand(time(NULL));	// Initialisation d'une seed random utilisant le temps actuel

	Base* base1;
	Base* base2;
	Base* base3;

	base1 = generate();
	base2 = generate();
	base3 = generate();

	std::cout << "--- identify by pointers ---" << std::endl;
	identify(base1);
	identify(base2);
	identify(base3);

	std::cout << "--- identify by references ---" << std::endl;
	identify(*base1);
	identify(*base2);
	identify(*base3);

	delete base1;
	delete base2;
	delete base3;

	return (0);
}
