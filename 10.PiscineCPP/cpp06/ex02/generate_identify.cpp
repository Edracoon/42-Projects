#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)	// Random Class Creation (A, B or C)
{
	int		randnb = rand() % 3 + 1; // Nombre entre 1 et 3

	switch ( randnb % 3 )	// 33% de chance d'avoir 0 / 1 / 2
	{
		case 0:
			return ( new A() );
		case 1:
			return ( new B() );
		case 2:
			return ( new C() );
	}
	return (NULL);
}

void	identify(Base* p)	// Find and display the real type of the Base (A, B or C)
{
	if ( dynamic_cast<A*>(p) != NULL ) // Si le dynamic cast echoue, il renvoie NULL
		std::cout << "A" << std::endl;
	if ( dynamic_cast<B*>(p) != NULL )
		std::cout << "B" << std::endl;
	if ( dynamic_cast<C*>(p) != NULL )
		std::cout << "C" << std::endl;
}

void	identify(Base& p)	// Same but without pointers
{
	if ( dynamic_cast<A*>(&p) != NULL )
		std::cout << "A" << std::endl;
	if ( dynamic_cast<B*>(&p) != NULL )
		std::cout << "B" << std::endl;
	if ( dynamic_cast<C*>(&p) != NULL )
		std::cout << "C" << std::endl;
}