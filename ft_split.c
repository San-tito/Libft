/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:54:26 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/14 19:09:26 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char *str, char c)
{
	size_t	counter;
	size_t	aux;

	counter = 0;
	aux = 0;
	while (*str)
	{
		if (*str == c)
			aux = 0;
		else if (aux == 0)
		{
			counter++;
			aux = 1;
		}
		str++;
	}
	return (counter);
}

static void	*ft_cleanmat(char **matrix, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(*(matrix + i++));
	free(matrix);
	return (NULL);
}

static char	**ft_putmat(char **matrix, char *str, size_t len, char c)
{
	size_t	i;
	size_t	buff;

	i = 0;
	while (i < len)
	{
		while (*str == c)
			str++;
		if (ft_strchr(str, c))
			buff = ft_strchr(str, c) - str;
		else
			buff = ft_strlen(str);
		*(matrix + i) = malloc((buff + 1) * sizeof(char));
		if (!*(matrix + i))
		{
			ft_cleanmat(matrix, i);
			return (NULL);
		}
		ft_strlcpy(*(matrix + i), str, buff + 1);
		str += buff;
		i++;
	}
	*(matrix + len) = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count((char *)s, c);
	matrix = malloc((count + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix = ft_putmat(matrix, (char *)s, count, c);
	return (matrix);
}
