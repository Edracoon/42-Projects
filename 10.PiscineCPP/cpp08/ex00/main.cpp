#include <iostream>
#include <vector>
#include <stack>
#include "easyfind.hpp"

int	main(void)
{
	std::list<int>			list1;
	std::vector<int>		vector1;

	list1.push_back(13);
	list1.push_back(26);
	list1.push_back(1);

	vector1.push_back(67);
	vector1.push_back(6);
	vector1.push_back(69);

	try
	{
		int		ret;

		ret = easyfind(list1, 26);
		std::cout << ret << std::endl;
	
		ret = easyfind(vector1, 6);
		std::cout << ret << std::endl;
		
		ret = easyfind(vector1, 69);
		std::cout << ret << std::endl;

		ret = easyfind(vector1, 999);
		std::cout << ret << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
