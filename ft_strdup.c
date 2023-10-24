/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:40:54 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/02 19:00:13 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	bf;

	bf = ft_strlen(s1) + 1;
	s2 = malloc(sizeof(char) * bf);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, bf);
	return (s2);
}
