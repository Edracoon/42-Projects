#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern( void ) { }
Intern::Intern( Intern const & rhs ) { *this = rhs; }
Intern::~Intern( void ) { }
Intern&	Intern::operator=( Intern const & rhs ) { (void)rhs; return (*this); }

Form*	Intern::makeForm(std::string type, std::string target)
{
	std::string tab[3];
	tab[0] = "shrubbery creation";
	tab[1] = "robotomy request";
	tab[2] = "presidential pardon";

	for (int i = 0 ; i < 3 ; i++)
	{
		if (tab[i] == type)
		{
			switch (i)
			{
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
				default:
					throw BadTypeException();
			}
		}
	}

	return (NULL);
}
