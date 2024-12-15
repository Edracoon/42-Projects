/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:35:51 by epfennig          #+#    #+#             */
/*   Updated: 2021/04/01 15:44:19 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int j;
	int used[255];

	if (ac == 3)
	{
		i = -1;
		j = 0;
		while (used[++i])
			used[i] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (av[i][j])
			{
				if (i == 2 && !(used[(unsigned char)av[i][j]]))
					used[(unsigned char)av[i][j]] = 1;
				else if (i == 1 && used[(unsigned char)av[i][j]] == 1)
				{
					write(1, &av[i][j], 1);
					used[(unsigned char)av[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
