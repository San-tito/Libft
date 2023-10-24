/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:33:14 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/02 20:55:04 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	bytes;

	bytes = count * size;
	if (size && (bytes / size) != count)
		return (NULL);
	mem = malloc(bytes);
	if (!mem)
		return (NULL);
	ft_bzero(mem, bytes);
	return (mem);
}
