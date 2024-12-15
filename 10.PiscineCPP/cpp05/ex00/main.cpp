#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	try	// J'essaie ce code : si des erreurs proviennent je recupere ces erreurs dans mon catch
	{
		Bureaucrat	Kev("Kevin", 1);
		std::cout << Kev << std::endl;
		Kev.decreaseGrade();
		std::cout << Kev << std::endl;

		Bureaucrat	Ed("Edgar", 149);
		std::cout << Ed << std::endl;
		Ed.decreaseGrade();
		std::cout << Ed << std::endl;
		Ed.decreaseGrade(); // Grade is now 151 == Error => Exception is catched
	}
	// catch (Bureaucrat::GradeTooLowException ex)	// -> catch specifique a mon erreur "too low"
	// {
	// 	std::cerr << ex.what() << std::endl;
	// }
	// catch (Bureaucrat::GradeTooHighException ex)	// -> catch specifique a mon erreur "too high"
	// {
	// 	std::cerr << ex.what() << std::endl;
	// }
	catch (std::exception& ex)	//	catch global qui va utiliser mes class
	{							//	qui heritent de std::exception
		std::cerr << ex.what() << std::endl;
	}
}
