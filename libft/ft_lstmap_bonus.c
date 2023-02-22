/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:43:05 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/09 05:29:48 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*newlst;

	if (!lst || !f || !del)
		return (0);
	node = ft_lstnew(NULL);
	if (!node)
		return (0);
	node->content = f(lst->content);
	newlst = node;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(NULL);
		if (!node->next)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		node->next->content = f(lst->content);
		node = node->next;
		lst = lst->next;
	}
	node->next = NULL;
	return (newlst);
}
