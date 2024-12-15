#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("Shrubbery", 145, 137)
{
	target = "UnnamedShrub";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("Shrubbery", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & rhs )
    : Form(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExec())
{
	*this = rhs;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	this->target = rhs.target;
    this->setSigned(rhs.getSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
    verifGrade(*this, executor);
    this->Action(this->target);
}

void	ShrubberyCreationForm::Action(const std::string target) const
{
	std::string		fileout = target + "_shrubbery";
	std::ofstream	ofs(fileout);

    std::cout << "Action ShrubberyCreationForm -> Planting a Tree..." << std::endl;

    ofs <<         fileout                       << std::endl << std::endl
        << "                             # #### ####" <<               std::endl
        << "                           ### /#|### |/####" <<           std::endl
        << "                          ##'\'/#/ '\'||/##/_/##/_#" << std::endl
        << "                        ###  '\'/###|/ '\'/ # ###" <<     std::endl
        << "                      ##_'\'_#'\'_'\'## | #/###_/_####" << std::endl
        << "                     ## #### # '\' #| /  #### ##/##" << std::endl
        << "                      __#_--###`  |{,###---###-~" <<       std::endl
        << "                                '\' }{" <<         std::endl
        << "                                 }}{" <<                   std::endl
        << "                                 }}{" <<                   std::endl
        << "                                 {{}" <<                   std::endl
        << "                           , -=-~{ .-^- _" <<           std::endl
        << "                                 `}" <<     std::endl
        << "                                  {"  <<                   std::endl;
}
