/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:36:45 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/12 13:41:30 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_stack *s, int *min)
{
	t_slist	*tmp;
	int		min_index;
	int		i;

	tmp = s->head;
	*min = tmp->nbr;
	i = 0;
	while (tmp)
	{
		i++;
		if (tmp->nbr < *min)
		{
			*min = tmp->nbr;
			min_index = i;
		}
		tmp = tmp->next;
	}
	return (min_index);
}

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

	i = stack_min(a, &min);
	while (a->head->nbr != min)
	{
		if (i <= ((a->size) / 2))
			rx(a, "ra");
		else
			(rrx(a, "rra"));
	}
	lis(*a);
	while (a->size > 0 && !has_keep_a(a))
	{
		if (a->head->keep_in_a)
			rx(a, "ra");
		else
			px(a, b, "pb");
	}
}
