/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:35:14 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/12 16:01:59 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t			c;
	unsigned int	num;

	c = 1;
	if (n < 0)
	{
		c++;
		num = n * -1;
	}
	else
		num = n;
	while (num > 9)
	{
		num /= 10;
		c++;
	}
	return (c);
}

static size_t	ft_tenpow(size_t power)
{
	int	base;

	base = 10;
	while (power-- != 1)
		base *= 10;
	return (base);
}

static char	*ft_setnbr(char *str, size_t i, unsigned int num, size_t len)
{
	while (len - 1)
	{
		*(str + i++) = (num / ft_tenpow(len - 1)) + '0';
		num %= ft_tenpow(len-- - 1);
	}
	*(str + i++) = num + '0';
	*(str + i) = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t			len;
	size_t			i;
	char			*str;
	unsigned int	num;

	i = 0;
	len = ft_intlen(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*(str + i++) = '-';
		num = n * -1;
		len--;
	}
	else
		num = n;
	ft_setnbr(str, i, num, len);
	return (str);
}
