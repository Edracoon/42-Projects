/* ************************************************************************** */$
/*                                                                            */$
/*                                                        :::      ::::::::   */$
/*   get_next_line.c                                    :+:      :+:    :+:   */$
/*                                                    +:+ +:+         +:+     */$
/*   By: epfennig </var/mail/epfennig>              +#+  +:+       +#+        */$
/*                                                +#+#+#+#+#+   +#+           */$
/*   Created: 2021/03/29 13:05:13 by epfennig          #+#    #+#             */$
/*   Updated: 2021/03/29 17:03:29 by epfennig         ###   ########.fr       */$
/*                                                                            */$
/* ************************************************************************** */$
$
#include "get_next_line.h"$
$
int		ft_strlen(char *str)$
{$
	int	i = 0;$
$
	while (str[i] != '\0')$
		i++;$
	return (i);$
}$
$
char	*ft_strchr(char *str, int c)$
{	$
	while (*str != c)$
	{$
		if (*str == '\0')$
			return (NULL);$
		str++;$
	}$
	return (str);$
}$
$
char	*ft_strjoin(char *s1, char *s2)$
{$
	int i = 0;$
	int j = 0;$
	char *dest;$
$
	if (!s1 || !s2 || !(dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))$
		return (NULL);$
	while (s1[i] != '\0')$
	{$
		dest[j] = s1[i];$
		i++;$
		j++;$
	}$
	i = 0;$
	while (s2[i] != '\0')$
	{$
		dest[j] = s2[i];$
		i++;$
		j++;$
	}$
	dest[j] = '\0';$
	return (dest);$
	$
}$
$
char	*ft_substr(char *str, int start, int len)$
{$
	int		i = 0;$
	int		j = 0;$
	char	*dest;$
$
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))$
		return (NULL);$
	while (str[i] != '\0')$
	{$
		if (i >= start && j < len)$
		{$
			dest[j] = str[i];$
			j++;$
		}$
		i++;$
	}$
	dest[j] = '\0';$
	return (dest);$
}$
$
char	*ft_memalloc(int size)$
{$
	int 	i;$
	char	*str;$
$
	i = 0;$
	if (!(str = malloc(sizeof(char) * size)))$
		return (NULL);$
	str[0] = 0;$
	return (str);$
}$
$
int		ft_strfree(char **str)$
{$
	if (*str)$
	{$
		free(*str);$
		*str = NULL;$
		return (1);$
	}$
	return (0);$
}$
$
char *ft_strdup(char *str)$
{$
	char *dest;$
	int i = 0;$
$
	while (str[i])$
		i++;$
	if (!(dest = malloc(sizeof(char) * i + 1)))$
		return (NULL);$
	i = 0;$
	while (str[i] != '\0')$
	{$
		dest[i] = str[i];$
		i++;$
	}$
	dest[i] = '\0';$
	return (dest);$
}$
$
int	get_next_line(char **line)$
{$
	ssize_t ret;$
	char	buff[500];$
	static char	*str;$
	char	*temp;$
$
	if (!line)$
		return (-1);$
	str == NULL ? str = ft_memalloc(1) : NULL;$
	while (!(ft_strchr(str, '\n')) && (ret = read(0, buff, 499)) > 0)$
	{$
		buff[ret] = '\0';$
		temp = ft_strjoin(str, buff);$
		ft_strfree(&str);$
		str = temp;$
	}$
	if (ret == 0)$
		*line = ft_strdup(str);$
	else if (ret > 0)$
		*line = ft_substr(str, 0, (ft_strchr(str, '\n') - str));$
	else$
		return (-1);$
	temp = ft_strdup(str + (ft_strlen(*line) + (ret > 0 ? +1 : +0)));$
	ft_strfree(&str);$
	str = temp;$
	return (ret == 0 ? 0 * ft_strfree(&str) : 1);$
$
}$
