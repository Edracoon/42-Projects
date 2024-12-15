#include "Form.hpp"
#include "Bureaucrat.hpp"

// === Constructeur par defaut ===
Form::Form( void ) : _name("DefaultFile"), _gradeSign(150), _gradeExec(150)
{
	_signed = false;
}

// === Constructeur par parametre ===
Form::Form( std::string name, const int gradeSign, const int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	_signed = false;
}

// === Constructeur par copy ===
Form::Form( Form const & rhs ) : _name(rhs.getName()), _gradeSign(rhs.getGradeSign()), _gradeExec(rhs.getGradeExec())
{
	*this = rhs;
}

// === Destructor ===
Form::~Form( void )
{
	;
}

// === Operators ===
Form&	Form::operator=( Form const & rhs )
{
	this->_signed = rhs._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& ofs, Form const & rhs)
{
	std::cout << rhs.getName() << ", signed: " << rhs.getSigned() << ", Grade to sign: "
			<< rhs.getGradeSign() << ", Grade to exec: " << rhs.getGradeExec();
	return (ofs);
}

// == Getters ===
std::string	Form::getName() const {
	return (_name);
}

bool				Form::getSigned() const {
	return (_signed);
}

int			Form::getGradeSign() const {
	return (_gradeSign);
}

int			Form::getGradeExec() const {
	return (_gradeExec);
}

// === Setters ===
void		Form::setSigned(bool b) {
	this->_signed = b;
}

// === beSigned ===
void		Form::beSigned(Bureaucrat & rhs)
{
	if (rhs.getNote() <= this->_gradeSign)
	{
		this->_signed = true;
		rhs.signForm(*this, true);
	}
	else
	{
		rhs.signForm(*this, false);
		throw Form::GradeTooLowException();
	}
}

void		Form::verifGrade(Form const & form, Bureaucrat const & executor) const
{
	if (form._signed == false)
		throw Form::NotSignedException();
	if (executor.getNote() > form._gradeExec)
		throw Form::GradeTooLowException();
}