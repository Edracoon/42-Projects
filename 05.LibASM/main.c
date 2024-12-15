/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:41:17 by epfennig          #+#    #+#             */
/*   Updated: 2021/05/10 13:25:31 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

extern size_t	ft_strlen(char *str);
extern char		*ft_strcpy(char *dst, char *src);
extern int		ft_strcmp(const char *s1, const char *s2);
extern ssize_t	ft_write(int fd, const void *buf, size_t size);
extern ssize_t	ft_read(int fd, void *buf, size_t size);
extern char		*ft_strdup(char *str);

void	ft_main_strlen(void)
{
	printf("\n----ft_strlen---\n");
	printf("ft_strlen : %zu |\n", ft_strlen("Bonsoir je suis une string haha ^^"));
	printf("strlen    : %zu |\n", strlen("Bonsoir je suis une string haha ^^"));
	printf("---------------|\n");
	printf("ft_strlen : %zu |\n",  ft_strlen("haha tellement bien d'être une string :P"));
	printf("strlen    : %zu |\n", strlen("haha tellement bien d'être une string :P"));
	printf("---------------|\n");
	printf("ft_strlen : %zu |\n", ft_strlen("J'adore strlen serieux"));
	printf("strlen    : %zu |\n", strlen("J'adore strlen serieux"));
	printf("---------------|\n");
	printf("ft_strlen : %zu  |\n", ft_strlen(""));
	printf("strlen    : %zu  |\n", strlen(""));
	printf("---------------|\n");
	printf("ft_strlen : %zu  |\n", ft_strlen("\n"));
	printf("strlen    : %zu  |\n", strlen("\n"));
	printf("---------------|\n");
	printf("ft_strlen : %zu  |\n", ft_strlen("1"));
	printf("strlen    : %zu  |\n", strlen("1"));
	printf("----------------");
	printf("\n");
}

void	ft_main_strcpy()
{
	char	src[] = "Bonsoir je suis la src";
	char	dest[] = "Bonsoir je suis la dest haha ^^";

	printf("----------------ft_strcpy-----------------\n");
	printf("ft_strcpy : dst= '%s'|\n", ft_strcpy(dest, src));
	printf("strcpy    : dst= '%s'|\n", strcpy(dest, src));
	printf("------------------------------------------\n");
}

void	ft_main_strcmp()
{
	char	str1[] = "Bonsoir je suis la src";
	char	str2[] = "Bonsoir je suis la dest haha ^^";

	printf("---------ft_strcmp-------\n");
	printf("ft_strcmp : ret = %i    |\n", ft_strcmp(str1, str2));
	printf("strcmp    : ret = %i    |\n", strcmp(str1, str2));
	printf("-------------------------\n");
}

void	ft_main_write()
{
	char str[] = "Bonsoir je suis la src";

	printf("---------------ft_write------------\n");
	printf(" | ret = %zi |\n", ft_write(1, str, ft_strlen(str)));
	printf(" | ret = %zi |\n", write(1, str, ft_strlen(str)));
	printf("-----------------------------------\n");
}

void	ft_main_read()
{
	char str[250];

	printf("----ft_read----\n");
	printf("ret = %zi      |\n", ft_read(open("read.txt", O_RDONLY), str, 250));
	printf("ret = %zi      |\n", read(open("read.txt", O_RDONLY), str, 250));
	printf("---------------\n");
}

void	ft_main_strdup()
{
	char	str[] = "yessay";

	printf("---ft_strdup------\n");
	printf("dst = '%s'   |\n", ft_strdup(str));
	printf("dst = '%s'   |\n", strdup(str));
	printf("------------------\n");
}

int	main(void)
{
	ft_main_strlen();
	ft_main_strcpy();
	ft_main_strcmp();
	ft_main_write();
	ft_main_read();
	ft_main_strdup();
	return (0);
}
