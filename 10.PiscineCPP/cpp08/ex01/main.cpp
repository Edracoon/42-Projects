#include "Span.hpp"
#include <list>

int	main(void)
{
	try
	{
		{
			Span	list(5);

			list.addNumber(-8);
			list.addNumber(-10);
			list.addNumber(5);
			list.addNumber(190);
			std::cout << "shortest span = " << list.shortestSpan() << std::endl;
			std::cout << "longest span = " << list.longestSpan() << std::endl;

			Span list2 = list;
			list2.addNumber(-100);
			std::cout << "shortest span = " << list2.shortestSpan() << std::endl;
			std::cout << "longest span = " << list2.longestSpan() << std::endl;

			std::cout << "shortest span = " << list.shortestSpan() << std::endl;
			std::cout << "longest span = " << list.longestSpan() << std::endl;

			Span sp = Span(5);
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		{
			Span except(2);
			except.addNumber(6);
			except.addNumber(19);
			except.addNumber(4); // container full
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try {
		Span except2(1);
		except2.shortestSpan(); } // Size invalid 
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl; }

	try {
		Span except3(4);
		except3.addNumber(2);
		std::cerr << except3.shortestSpan() << std::endl; } // Not enough numbers
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl; }

	try {	// 10000 numbers
		std::vector<int>					vect(10000);
		std::vector<int>::const_iterator	it = vect.begin();
		std::vector<int>::const_iterator	ite = vect.end();

		Span	vectthousand = Span(it, ite);

		std::cout << vectthousand.longestSpan() << std::endl;
		std::cout << vectthousand.shortestSpan() << std::endl;

		vectthousand.addNumber(15);	// container full
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl; }
}
