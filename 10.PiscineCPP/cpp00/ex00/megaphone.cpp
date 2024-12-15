#include <iostream>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int	j = 0;
		for (int i = 1 ; av[i] != NULL ; i++)
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					av[i][j] = toupper(av[i][j]);
				j++;
			}
		}
		j = 1;
		while (av[j])
		{
			std::cout << av[j];
			j++;
		}
		std::cout << std::endl;
	}
}
