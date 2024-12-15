#include <iostream>
#include "Phonebook.class.hpp"
#include "Contact.class.hpp"

int	main(void)
{
	std::string	buf;
	Phonebook	instance;

	while (1)
	{
		std::cout << "*> ";
		std::cin >> buf;
		if (buf == "ADD")
			instance.addcontact();
		else if (buf == "SEARCH")
			instance.search();
		else if (buf == "EXIT")
			return (0);
	}
}
