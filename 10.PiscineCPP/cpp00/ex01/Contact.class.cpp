#include "Contact.class.hpp"
#include <iostream>

Contact::Contact(void)
{
	// std::cout << "Constructor called Contact" << std::endl;
}

Contact::~Contact(void)
{
	// std::cout << "Destructor called Contact" << std::endl;
}

void	Contact::setFirstname(std::string str)
{
	this->firstname = str;
}

void	Contact::setLastname(std::string str)
{
	this->lastname = str;
}

void	Contact::setNickname(std::string str)
{
	this->nickname = str;
}

void	Contact::setPhonenumber(std::string str)
{
	this->phonenumber = str;
}

void	Contact::setDarkestsecret(std::string str)
{
	this->darkestsecret = str;
}

std::string	Contact::getFirstname()
{
	return (this->firstname);
}

std::string	Contact::getLastname()
{
	return (this->lastname);
}

std::string	Contact::getNickname()
{
	return (this->nickname);
}

std::string	Contact::getPhonenumber()
{
	return (this->phonenumber);
}

std::string	Contact::getDarkestsecret()
{
	return (this->darkestsecret);
}