#include <iostream>
#include "Array.hpp"

// int	main(void)
// {
// 	try
// 	{
// 		Array<unsigned int> test = Array<unsigned int>(5);

// 		Array<unsigned int> bonsoir = test;

// 		std::cout << "test[0] :" << test[0] << std::endl;
// 		test[0] = 2;
// 		std::cout << "test[0] :" << test[0] << std::endl;
// 		std::cout << "bonsoir[0] :" << bonsoir[0] << std::endl;

// 		Array<std::string> strs = Array<std::string>(4);
// 		std::cout << "str[2] :" << strs[2] << std::endl;
// 		strs[2] = "bonsoir";
// 		std::cout << "str[2] :" << strs[2] << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// }

#define MAX_VAL 750

int main(int, char**)
{
	Array<int>	numbers(MAX_VAL);
	int*		mirror = new int[MAX_VAL];

	srand(time(NULL));

	for (int i = 0; i < MAX_VAL; i++)	// Test pour comparer int[750] et Array[750]
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)	// Verification que toutes les valeurs sont egales
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;	// 750 : le max est 749
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	delete [] mirror;
	return 0;
}