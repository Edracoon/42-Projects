#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::srand(time(NULL));	// reset le temps pour avoir un rand() vraiment random (selon le temps)
	try	// J'essaie ce code : si des erreurs proviennent je recupere ces erreurs dans mon catch
	{
		std::cout << std::endl << "=== Bureaucrat ===" << std::endl;
		Bureaucrat	Kev("Kevin", 3);				// Creation de Kev
		std::cout << Kev << std::endl;				// Affichage de Kev
		Kev.increaseGrade();						// Decre du Grade
		std::cout << Kev << std::endl;				// Affiche de Kev

		Bureaucrat	Ed("Edgar", 138);				// Creation d'Ed
		std::cout << Ed << std::endl;				// Affichage d'Ed
		Ed.increaseGrade();							// incre du Grade
		std::cout << Ed << std::endl;				// Affiche d'Ed

		std::cout << std::endl << "=== ShrubberyCreationForm ===" << std::endl;
		ShrubberyCreationForm	shrub("maison");	// Shrub test
		std::cout << shrub << std::endl;			// Affichage Form
		shrub.beSigned(Ed);							// Signer le Form
		std::cout << shrub << std::endl;			// Affichage du Form
		shrub.execute(Ed);							// Execute le form

		ShrubberyCreationForm	copyshrub(shrub);	// Deep Copy Shrub
		std::cout << copyshrub << std::endl;

		std::cout << std::endl << "=== RobotomyRequestForm ===" << std::endl;
		Bureaucrat Micka("Micka", 1);
		RobotomyRequestForm	robo("Kevin");			// Robotomy test
		std::cout << robo << std::endl;				// Affichage Form
		robo.beSigned(Micka);						// Signer le Form
		std::cout << robo << std::endl;				// Affichage du Form
		robo.execute(Micka);						// Executer le form

		RobotomyRequestForm	copyrobo(robo);			// Deep Copy Robotomy
		std::cout << copyrobo << std::endl;

		std::cout << std::endl << "=== PresidentialPardonForm ===" << std::endl;
		PresidentialPardonForm	presidpardon("Kevin");		// PresidentialPardon test
		std::cout << presidpardon << std::endl;				// Affichage Form
		presidpardon.beSigned(Micka);						// Signer le Form
		std::cout << presidpardon << std::endl;				// Affichage du Form
		presidpardon.execute(Micka);						// Executer le form

		PresidentialPardonForm	copypardon(presidpardon);	// Deep Copy Robotomy
		std::cout << copypardon << std::endl;
	}
	catch (std::exception& ex)	//	catch global qui va utiliser mes class
	{							//	qui heritent de std::exception
		std::cerr << ex.what() << std::endl;
	}
}
