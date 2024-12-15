/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:25:06 by epfennig          #+#    #+#             */
/*   Updated: 2021/04/01 15:32:13 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int used[255];
	int i;
	int j;

	i = -1;
	j = 0;
	if (ac == 3)
	{
		while (used[++i])
			used[i] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (av[i][j])
			{
				if (!(used[(unsigned char)av[i][j]]))
				{
					used[(unsigned char)av[i][j]] = 1;
					write(1, &av[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
