/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:58:39 by epfennig          #+#    #+#             */
/*   Updated: 2021/06/02 17:56:33 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_data
{
	int	width;
	int	height;
	char	bgc;

	char	type;
	float	posx;
	float	posy;
	float	radius;
	char	c;

	char	*tab;
}	t_data;

char	*init_tab(t_data *d)
{
	int	i;
	char	*tab;

	i = -1;
	if ((d->width > 0 && d->width <= 300) && (d->height > 0 && d->height <= 300) && (d->bgc))
	{
		if (!(tab = malloc(sizeof(char) * (d->width * d->height) + 1)))
			return (NULL);
		while (++i < (d->width * d->height))
			tab[i] = d->bgc;
		tab[i] = 0;
		return (tab);
	}
	return (NULL);
}

int	check_data(t_data *d)
{
	if (!(d->type == 'c' || d->type == 'C'))
		return (0);
	if (!(d->radius > 0))
		return (0);
	return (1);
}

int	is_in_circle(t_data *d, float x, float y)
{
	float	dist;

	dist = sqrtf(powf(x - d->posx, 2.0) + powf(y - d->posy, 2.0));
	if (dist > d->radius)
		return (0);
	if (d->type == 'c' && (d->radius - dist < 1.00000))
		return (1);
	else if (d->type == 'C')
		return (2);
	return (0);
}

void	exec_one(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < d->height)
	{
		x = 0;
		while (x < d->width)
		{
			if (is_in_circle(d, (float)x, (float)y) > 0)
				d->tab[x + y * d->width] = d->c;
			x++;
		}
		y++;
	}
}

int		exec_boucle(t_data *d, FILE *file)
{
	int	ret;

	ret = fscanf(file, "%d %d %c\n", &d->width, &d->height, &d->bgc);
	if (ret != 3)
		return (-1);
	d->tab = init_tab(d);
	if (!(d->tab))
		return (-1);
	ret = fscanf(file, "%c %f %f %f %c\n", &d->type, &d->posx, &d->posy, &d->radius, &d->c);
	while (ret == 5)
	{
		if (check_data(d) == 1)
			exec_one(d);
		else
			return (-1);
		ret = fscanf(file, "%c %f %f %f %c\n", &d->type, &d->posx, &d->posy, &d->radius, &d->c);
	}
	if (ret != EOF)
		return (-1);
	return (1);
}

void	print_result(t_data *d)
{
	int	i = -1;

	while (++i < d->height)
	{
		write(1, d->tab + i * d->width, d->width);
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	int	ret;
	FILE *file;
	t_data d;

	if (ac == 2)
	{
		file = fopen(av[1], "r");
		if (!file)
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
		ret = exec_boucle(&d, file);
		if (ret == -1)
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
		print_result(&d);
		return (0);
	}
	write(1, "Error: argument\n", 16);
}
