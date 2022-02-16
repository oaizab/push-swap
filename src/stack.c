/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 08:35:14 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/16 16:46:01 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack(void)
{
	t_stack	*s;

	s = ft_calloc(1, sizeof(t_stack));
	if (!s)
		ft_error(NULL);
	return (s);
}

void	ft_push(t_stack *s, int n)
{
	t_slist	*l;

	l = ft_calloc(1, sizeof(t_slist));
	if (!l)
		ft_error(s);
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

int	ft_pop(t_stack *s)
{
	int		n;
	t_slist	*tmp;

	n = s->head->nbr;
	s->size--;
	tmp = s->head;
	s->head = s->head->next;
	if (s->size == 0)
		s->tail = NULL;
	free(tmp);
	return (n);
}

void	ft_addlast(t_stack *s, int n)
{
	t_slist	*l;

	if (s->size == 0)
		ft_push(s, n);
	else
	{
		l = ft_calloc(1, sizeof(t_slist));
		if (!l)
			ft_error(s);
		l->nbr = n;
		l->prev = s->tail;
		s->tail->next = l;
		s->tail = l;
		s->size++;
	}
}
