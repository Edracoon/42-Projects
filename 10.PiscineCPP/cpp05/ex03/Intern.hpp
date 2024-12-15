#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Form.hpp"

class Intern
{
	private:

	public:
			Intern( void );
			Intern( Intern const & rhs );
			~Intern( void );

			Form*	makeForm(std::string type, std::string target);

			Intern&	operator=( Intern const & rhs );

			class BadTypeException : public std::exception
			{
				virtual const char*	what( void ) const throw()
				{
					return ("Intern: Bad Form Type entered");
				}
			};
};

#endif