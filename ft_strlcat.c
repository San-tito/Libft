/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:28:14 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/02 19:48:54 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	sl;

	sl = ft_strlen(src);
	if (dstsize == 0 && dst == NULL)
		return (sl);
	dl = ft_strlen(dst);
	if (dl < dstsize)
		dstsize -= dl;
	else
		return (sl + dstsize);
	ft_strlcpy(dst + dl, src, dstsize);
	return (dl + sl);
}
