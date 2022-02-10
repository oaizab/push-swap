/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 08:35:14 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/10 09:45:10 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack(void)
{
	t_stack	*s;

	s = ft_calloc(1, sizeof(t_stack));
	return (s);
}

void	ft_push(t_stack *s, int n)
{
	t_slist	*l;

	l = ft_calloc(1, sizeof(t_slist));
	l->nbr = n;
	if (s->size == 0)
	{
		s->head = l;
		s->tail = l;
	}
	else
	{
		s->head->prev = l;
		l->next = s->head;
		s->head = l;
	}
	s->size++;
}
