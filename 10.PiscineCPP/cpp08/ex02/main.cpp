#include "mutantstack.hpp"
/*
int	main(void)
{
	Mutantstack<int>	stack1;
	Mutantstack<int>	stack2;

	stack1.push(5);
	stack1.push(9);
	stack1.push(14);

	Mutantstack<int>::iterator	it = stack1.begin();
	Mutantstack<int>::iterator	ite = stack1.end();

	stack2 = stack1;
	stack2.push(19);
	stack2.push(60);

	std::cout << "stack1 iteration : " << std::endl;
	for ( ; it != ite ; ++it)
		std::cout << *it << std::endl;

	std::deque<int>::iterator it2 = stack2.begin();
	std::deque<int>::iterator ite2 = stack2.end();

	std::cout << "stack2 iteration : " << std::endl;
	for ( ; it2 != ite2 ; ++it2)
		std::cout << *it2 << std::endl;
}
*/

int		main( void )
{
	Mutantstack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	Mutantstack<int>::iterator it = mstack.begin();
	Mutantstack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
