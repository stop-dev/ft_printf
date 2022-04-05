/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:07:36 by stopping          #+#    #+#             */
/*   Updated: 2020/11/13 20:58:55 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*ptr_start;

	if (!lst)
		return (0);
	if (!(ptr_start = ft_lstnew(f((void *)(lst->content)))))
	{
		ft_lstclear(&ptr_start, del);
		return (0);
	}
	while ((lst = lst->next) != 0)
	{
		if (!(new = ft_lstnew(f((void *)(lst->content)))))
		{
			ft_lstclear(&ptr_start, del);
			return (0);
		}
		ft_lstadd_back(&ptr_start, new);
	}
	return (ptr_start);
}
