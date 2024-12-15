#include <iostream>
#include "Karen.hpp"

Karen::Karen()
{
	this->tab[0] = "DEBUG";
	this->tab[1] = "INFO";
	this->tab[2] = "WARNING";
	this->tab[3] = "ERROR";

	this->function[0] = &Karen::debug;
	this->function[1] = &Karen::info;
	this->function[2] = &Karen::warning;
	this->function[3] = &Karen::error;
}

Karen::~Karen()
{
	;
}

void	Karen::complain(std::string level)
{
	for (int i = 0 ; i <= 4 ; i++)
	{
		if (i == 4 || level == this->tab[i])
		{
			switch (i)
			{
				case 0:
					(this->*function[0])();
				case 1:
					(this->*function[1])();
				case 2:
					(this->*function[2])();
				case 3:
					(this->*function[3])();
					return ;
				default:
					std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			}
		}
	}
}

void Karen::debug(void)
{
	std::cout << "I love to get extra bacon" <<
				"for my 7XL-double-cheese-triple-pickle-special-ketchup burger." <<
				"I just love it!" << std::endl;
}

void Karen::info(void)
{
	std::cout << "I cannot believe adding extra" <<
				 "bacon cost more money. You don't put enough!" <<
				 "If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." <<
				 "I’ve been coming here for years and you just started" <<
				 "working here last month." << std::endl;
}

void Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}