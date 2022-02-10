/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:51:26 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/10 13:51:33 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack *s, char *msg)
{
	t_slist	*tmp;

	if (s->size == 2)
	{
		s->head->next = NULL;
		s->head->prev = s->tail;
		s->tail->next = s->head;
		s->tail->prev = NULL;
		tmp = s->tail;
		s->tail = s->head;
		s->head = tmp;
	}
	else if (s->size > 2)
	{
		tmp = s->head->next;
		tmp->next->prev = s->head;
		s->head->next = tmp->next;
		s->head->prev = tmp;
		tmp->prev = NULL;
		tmp->next = s->head;
		s->head = tmp;
	}
	if (msg && (s->size >= 2))
		ft_printf("%s\n", msg);
}

void	ss(t_stack *a, t_stack *b, char *msg)
{
	sx(a, NULL);
	sx(b, NULL);
	if (msg)
		ft_printf("s\n", msg);
}
