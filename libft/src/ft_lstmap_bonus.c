/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:26:37 by oaizab            #+#    #+#             */
/*   Updated: 2021/11/12 00:36:24 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*l;
	t_list	*temp;
	void	*ct;

	if (!del)
		del = free;
	if (!lst || !f)
		return (NULL);
	l = NULL;
	while (lst)
	{
		ct = f(lst->content);
		temp = ft_lstnew(ct);
		if (!temp)
		{
			ft_lstclear(&l, del);
			break ;
		}
		ft_lstadd_back(&l, temp);
		lst = lst->next;
	}
	return (l);
}
