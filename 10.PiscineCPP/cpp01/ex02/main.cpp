#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;
	std::string& stringRef = str;

	std::cout << "Adress of the string : \t\t\t" << &str << std::endl;
	std::cout << "Adress of the string (stringPTR) : \t" << stringPTR << std::endl;
	std::cout << "Adress of the string (stringRef) : \t" << &stringRef << std::endl;

	std::cout << "String (stringPTR) : \t" << *stringPTR << std::endl;
	std::cout << "String (stringRef) : \t" << stringRef << std::endl;
	return (0);
}
