/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig </var/mail/epfennig>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:33:09 by epfennig          #+#    #+#             */
/*   Updated: 2021/03/29 18:51:24 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i, j;
	int		used[255];
	
	if (ac == 3)
	{
		i = 0;
		while (i < 256)
		{
			used[i] = 0;
			i++;
		}
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (av[i][j])
			{
				if (i == 2 && !used[(unsigned char)av[i][j]])
				{
					used[(unsigned char)av[i][j]] = 1;
				}
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

