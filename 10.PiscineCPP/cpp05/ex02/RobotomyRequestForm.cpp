#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("Robotomy", 72, 45)
{
	target = "UnnamedRobotomy";
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("Robotomy", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs )
	: Form(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExec())
{
	*this = rhs;
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	this->target = rhs.target;
	this->setSigned(rhs.getSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	;
}

void	RobotomyRequestForm::Action( void ) const
{
	int random = rand() % 100 + 1;

	std::cout << "Action RobotomyRequestForm : *drilling noise* ..." << std::endl;
	if (random >= 50)
		std::cout << this->target  << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy Failure" << std::endl;
}
