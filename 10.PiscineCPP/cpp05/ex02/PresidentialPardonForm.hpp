#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"
#include <string>
#include <fstream>

class PresidentialPardonForm : public Form
{
	private:
			std::string	target;
	public:
			PresidentialPardonForm( void );
			PresidentialPardonForm( std::string target );
			PresidentialPardonForm( PresidentialPardonForm const & rhs );
			virtual ~PresidentialPardonForm();

			PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);
			virtual void	Action( void ) const;
};

#endif
