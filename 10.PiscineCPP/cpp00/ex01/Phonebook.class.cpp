#include "Phonebook.class.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook(void)
{
	// std::cout << "Constructor called phonebook" << std::endl;
	this->i = 0;
}

Phonebook::~Phonebook(void)
{
	// std::cout << "Destructor called phonebook" << std::endl;
}

void	Phonebook::show_info(int n)
{
	std::cout << "Firstname:\t" << this->tab[n - 1].getFirstname() << std::endl;
	std::cout << "Lastname:\t" << this->tab[n - 1].getLastname() << std::endl;
	std::cout << "Nickname:\t" << this->tab[n - 1].getNickname() << std::endl;
	std::cout << "Phone number:\t" << this->tab[n - 1].getPhonenumber() << std::endl;
	std::cout << "Darkest secret:\t" << this->tab[n - 1].getDarkestsecret() << std::endl;
}

void	print_ten_char(std::string str)
{
	for (int i = 0; i < 9; i++)
		std::cout << str[i];
	std::cout << ".|";
}

void	Phonebook::search(void)
{
	std::string	str;
	int			n;
	for (int i = 0 ; i < this->i ; i++)
	{
		std::cout <<  std::setw(10) << i + 1 << "|";
		if (this->tab[i].getFirstname().length() <= 10)
			std::cout <<  std::setw(10) << this->tab[i].getFirstname() << "|";
		else
			print_ten_char(this->tab[i].getFirstname());
		if (this->tab[i].getLastname().length() < 10)
			std::cout << std::setw(10) << this->tab[i].getLastname() << "|";
		else
			print_ten_char(this->tab[i].getLastname());
		if (this->tab[i].getNickname().length() < 10)
			std::cout << std::setw(10) << this->tab[i].getNickname() << "|";
		else
			print_ten_char(this->tab[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "Select a number : ";
	std::cin >> str;
	for (size_t i = 0 ; i < str.length() ; i++)
	{
		if (!(std::isdigit(str[i])))
		{
			std::cout << "Please enter a number between 1 and 8 to see the apropriate contact" << std::endl;
			return ;
		}
	}
	n = (int)std::stod(str);
	if (n >= 1 && n <= 8)
		this->show_info(n);
	else
		std::cout << "Please enter a number between 1 and 8 to see the apropriate contact" << std::endl;
}

void	Phonebook::addcontact(void)
{
	std::string buff;

	if (this->i > 7)
		std::cout << "Error: No space left to add a contact" << std::endl;
	else
	{
		std::cout << "first name : ";
		std::cin >> buff;
		this->tab[this->i].setFirstname(buff);
		std::cout << "last name : ";
		std::cin >> buff;
		this->tab[this->i].setLastname(buff);
		std::cout << "nickname : ";
		std::cin >> buff;
		this->tab[this->i].setNickname(buff);
		std::cout << "phone number : ";
		std::cin >> buff;
		this->tab[this->i].setPhonenumber(buff);
		std::cout << "darkest secret : ";
		std::cin >> buff;
		this->tab[this->i].setDarkestsecret(buff);
		this->i++;
	}
}
