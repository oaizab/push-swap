/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:31 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/17 04:20:29 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack *a)
{
	int		i;
	t_slist	*tmp;

	tmp = a->head;
	i = 0;
	while (i < a->size - 1)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	ft_sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->head->nbr;
	y = a->head->next->nbr;
	z = a->tail->nbr;
	if (x > y && x < z)
		sx(a, "sa");
	else if (y > z && y < x)
		(sx(a, "sa"), rrx(a, "rra"));
	else if (z > y && z < x)
		rx(a, "ra");
	else if (x > z && x < y)
		rrx(a, "rra");
	else if (z > x && z < y)
		(sx(a, "sa"), rx(a, "ra"));
}

void	push_min(t_stack *a, t_stack *b)
{
	int	i;
	int	min;

	i = stack_min(a, &min);
	while (a->head->nbr != min)
	{
		if (i <= ((a->size) / 2))
			rx(a, "ra");
		else
			rrx(a, "rra");
	}
	px(a, b, "pb");
	i = stack_min(a, &min);
	while (a->head->nbr != min)
	{
		if (i <= ((a->size) / 2))
			rx(a, "ra");
		else
			rrx(a, "rra");
	}
	px(a, b, "pb");
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	push_min(a, b);
	ft_sort_three(a);
	px(b, a, "pa");
	px(b, a, "pa");
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (ft_sorted(a))
		return ;
	if (a->size == 3)
		ft_sort_three(a);
	else if (a->size == 5)
		ft_sort_five(a, b);
	else
	{
		push_b(a, b);
		push_a(a, b);
	}
}
