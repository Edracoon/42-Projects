#include <iostream>
#include <string>
#include <limits>
#include <cmath>

void	convert_char(double convert);
void	convert_int(double convert);
void	convert_float(double convert);
void	convert_double(double convert);

int		main(int ac, char **av)
{
	double	to_convert;		/* Stockage dans un double 
							permet de stocker n'importe
							quel 'sous int' , c'est le
							type le plus grand */
	if (ac == 2)
	{
		std::string str(av[1]);
		if (av[1][0] && !(av[1][1]) && (av[1][0] < '0' || av[1][0] > '9'))	// les chars sont acceptés
			to_convert = static_cast<double>(av[1][0]);						// stod pour un char
		else
		{
			try { to_convert = stod(str); }
			catch (std::exception & e) { std::cerr << e.what() << std::endl; return (0); }
		}
		std::cout << "char: ";
		convert_char(to_convert);
		std::cout << "int: ";
		convert_int(to_convert);
		std::cout << "float: ";
		convert_float(to_convert);
		std::cout << "double: ";
		convert_double(to_convert);
	}
	else
		std::cout << "Error: Number of arguments invalid -> [./cast] [type]" << std::endl;
	return (0);
}
