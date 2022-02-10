/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:37:00 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/10 15:02:50 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack *s, char *msg)
{
	t_slist	*tmp;

	if (s->size == 2)
		sx(s, NULL);
	else if (s->size > 2)
	{
		tmp = s->head->next;
		tmp->prev = NULL;
		s->head->next = NULL;
		s->head->prev = s->tail;
		s->tail->next = s->head;
		s->tail = s->head;
		s->head = tmp;
	}
	if (msg && (s->size >= 2))
		ft_printf("%s\n", msg);
}

void	rr(t_stack *a, t_stack *b, char *msg)
{
	rx(a, NULL);
	rx(b, NULL);
	if (msg)
		ft_printf("%s\n", msg);
}
