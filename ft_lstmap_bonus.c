/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:08:36 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/15 18:37:04 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*aux;
	void	*fun;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		fun = f((*lst).content);
		aux = ft_lstnew(fun);
		if (!aux)
		{
			ft_lstclear(&list, del);
			free(fun);
			return (NULL);
		}
		ft_lstadd_back(&list, aux);
		lst = (*lst).next;
	}
	return (list);
}
