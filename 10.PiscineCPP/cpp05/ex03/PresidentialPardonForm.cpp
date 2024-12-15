#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("Pardon", 25, 5)
{
	target = "UnnamedPardon";
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("Pardon", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & rhs )
	: Form(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExec())
{
	*this = rhs;
}

PresidentialPardonForm&  PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	this->target = rhs.target;
	this->setSigned(rhs.getSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	verifGrade(*this, executor);
	this->Action(this->target);
}

void	PresidentialPardonForm::Action(const std::string target) const
{
	std::cout << "Action PresidentialPardonForm : ..." << std::endl;
	std::cout << target << " has been pardonned by Zafod Beeblebrox" << std::endl;
}
