#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Form.hpp"
#include <string>
#include <fstream>

class RobotomyRequestForm : public Form
{
	private:
			std::string	target;
	public:
			RobotomyRequestForm( void );
			RobotomyRequestForm( std::string target );
			RobotomyRequestForm( RobotomyRequestForm const & rhs );
			~RobotomyRequestForm();
			RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);
			virtual void	execute( Bureaucrat const & executor ) const;
			void	Action(const std::string target) const;
};

#endif