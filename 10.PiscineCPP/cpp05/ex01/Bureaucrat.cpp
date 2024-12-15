#include "Bureaucrat.hpp"

/// === Constructors ===
Bureaucrat::Bureaucrat( void ) { } // -> Default

Bureaucrat::Bureaucrat( const std::string name, int note ) : _name(name), _note(note) // -> Parametric
{
	if (note < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (note > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & rhs ) : _name(rhs.getName()) // -> Copy
{
	*this = rhs;
}

// === Operator egal ===
Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_note = rhs.getNote();
	return (*this);
}

// === Operator affichage ===
std::ostream&	operator<<(std::ostream& ofs, Bureaucrat const & rhs)
{
	std::cout << "<" << rhs.getName() << "> bureaucrat grade " << rhs.getNote(); 
	return (ofs);
}

// === Destructor ===
Bureaucrat::~Bureaucrat( void ) { } 

// === Getters ===
const std::string	Bureaucrat::getName( void ) const {
	return (this->_name);
}

int		Bureaucrat::getNote( void ) const {
	return (this->_note);
}

// === Incr Note / Decr Note ===
void				Bureaucrat::increaseGrade()
{
	if (this->_note == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_note -= 1;
}

void				Bureaucrat::decreaseGrade()
{
	if (this->_note == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_note += 1;
}

// === signForm ===
void				Bureaucrat::signForm(Form const & rhs, bool success)
{
	if (success)
		std::cout << "<" << this->getName() << "> signs <" << rhs.getName() << ">" << std::endl; 
	else
		std::cout << "<" << this->getName() << "> cannot signs because "; 
}