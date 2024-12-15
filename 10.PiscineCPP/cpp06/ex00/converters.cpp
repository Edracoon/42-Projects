#include <iostream>
#include <string>
#include <limits>
#include <cmath>

void	convert_char(double convert)
{
	if (convert <= 32 || convert >= 127)
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	char	c = static_cast<char>(convert);
	if (c == 0)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << c << std::endl;
	return ;
}

void	convert_int(double convert)
{
	if (convert > INT_MAX || convert < INT_MIN || (convert != convert)) // Verifier que c'est un 'NaN' : x!=x
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	int		c = static_cast<int>(convert);
	std::cout << c << std::endl;
}

void	convert_float(double convert)
{
	float	c = static_cast<float>(convert);

	if (convert != convert)
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (!(c - static_cast<int>(c)))
		std::cout << c << ".0f" <<std::endl;
	else
		std::cout << c << "f" << std::endl;
}

void	convert_double(double convert)
{
	if (!(convert - static_cast<int>(convert)))
		std::cout << convert << ".0" <<std::endl;
	else
		std::cout << convert << "" << std::endl;
}
