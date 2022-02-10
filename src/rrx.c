/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:10:27 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/10 15:03:32 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_stack *s, char *msg)
{
	t_slist	*tmp;

	if (s->size == 2)
		sx(s, NULL);
	else if (s->size > 2)
	{
		tmp = s->tail->prev;
		tmp->next = NULL;
		s->tail->next = s->head;
		s->tail->prev = NULL;
		s->head->prev = s->tail;
		s->head = s->tail;
		s->tail = tmp;
	}
	if (msg && (s->size >= 2))
		ft_printf("%s\n", msg);
}

void	rrr(t_stack *a, t_stack *b, char *msg)
{
	rrx(a, NULL);
	rrx(b, NULL);
	if (msg)
		ft_printf("%s\n", msg);
}
