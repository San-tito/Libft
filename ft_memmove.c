/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:48:23 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/02 20:52:13 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!(char *)src && !(char *)dst)
		return (NULL);
	if (dst > src)
		while (len--)
			*((char *)dst + len) = *((char *)src + len);
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
