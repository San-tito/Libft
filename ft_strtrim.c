/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:28:24 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/10 15:49:25 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1);
		while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
			start++;
		if (end <= start)
			return (ft_strdup(""));
		while (*(s1 + end - 1) && ft_strchr(set, *(s1 + end - 1))
			&& end > start)
			end--;
		str = malloc(sizeof(char) * ((end - start) + 1));
		if (str)
			ft_strlcpy(str, s1 + start, (end - start) + 1);
	}
	return (str);
}
