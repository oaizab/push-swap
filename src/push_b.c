/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:36:45 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/13 15:00:39 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_keep_a(t_stack *s)
{
	t_slist	*tmp;

	tmp = s->head;
	while (tmp)
	{
		if (!tmp->keep_in_a)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_b(t_stack *a, t_stack *b)
{
	int	min;
	int	i;
	int	n;

	i = stack_min(a, &min);
	n = 0;
	while (a->head->nbr != min)
	{
		if (i <= ((a->size) / 2))
		{
			rx(a, NULL);
			n++;
		}
		else
		{
			(rrx(a, NULL));
			n--;
		}
	}
	lis(*a);
	while (n != 0)
	{
		if (n > 0)
		{
			rrx(a, NULL);
			n--;
		}
		else
		{
			(rx(a, NULL));
			n++;
		}
	}
	while (a->size > 0 && !has_keep_a(a))
	{
		if (a->head->keep_in_a)
			rx(a, "ra");
		else
			px(a, b, "pb");
	}
}
