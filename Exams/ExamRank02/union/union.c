/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig </var/mail/epfennig>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:13:52 by epfennig          #+#    #+#             */
/*   Updated: 2021/03/29 17:45:39 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int used[255];
	int i, j;

	if (ac != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (i < 255)
		used[i++] = 0;
	i = 1;
	while (i <= 2)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(used[(unsigned char)av[i][j]]))
			{
				used[(unsigned char)av[i][j]] = 1;
				ft_putchar(av[i][j]);
			}
			j++;
		}
		i++;
	}
	ft_putchar('\n');
	return (0);
}
