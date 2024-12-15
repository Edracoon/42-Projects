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

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	verifGrade(*this, executor);
	this->Action(this->target);
}

void	RobotomyRequestForm::Action(const std::string target) const
{
	int random = rand() % 100 + 1;

	std::cout << "Action RobotomyRequestForm : *drilling noise* ..." << std::endl;
	if (random >= 50)
		std::cout << target  << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy Failure" << std::endl;
}
