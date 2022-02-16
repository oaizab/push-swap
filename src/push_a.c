/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:35:18 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/16 15:24:28 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pose_a(t_stack *a, int n)
{
	t_slist	*tmp_a;
	int		i[2];

	tmp_a = a->head;
	if (n < a->head->nbr && n > a->tail->nbr)
		return (0);
	i[0] = 0;
	while (++i[0] < a->size / 2)
	{
		if (n > tmp_a->nbr && n < tmp_a->next->nbr)
			return (i[0]);
		tmp_a = tmp_a->next;
	}
	tmp_a = a->tail;
	i[0] = a->size + 1;
	while (--i[0] > a->size / 2)
	{
		if (n > tmp_a->prev->nbr && n < tmp_a->nbr)
			return (i[0] - a->size - 1);
		tmp_a = tmp_a->prev;
	}
	i[0] = stack_max(a, &i[1]);
	if (i[0] < a->size / 2)
		return (i[0] - 1);
	return (i[0] - a->size - 1);
}

void	first_half(t_stack *a, t_stack *b, int t[])
{
	int		i;
	int		j;
	t_slist	*tmp_b;

	tmp_b = b->head;
	j = 0;
	t[0] = -a->size;
	t[1] = b->size;
	while (j < b->size / 2)
	{
		if (ft_nmoves(0, j) >= ft_nmoves(t[0], t[1]))
			break ;
		i = find_pose_a(a, tmp_b->nbr);
		if (ft_nmoves(i, j) < ft_nmoves(t[0], t[1]))
		{
			t[0] = i;
			t[1] = j;
		}
		tmp_b = tmp_b->next;
		j++;
	}
}

void	second_half(t_stack *a, t_stack *b, int t[])
{
	int		i;
	int		j;
	t_slist	*tmp_b;

	tmp_b = b->tail;
	j = b->size;
	while (j > b->size / 2)
	{
		if (ft_nmoves(0, j - b->size - 1) >= ft_nmoves(t[0], t[1]))
			break ;
		i = find_pose_a(a, tmp_b->nbr);
		if (ft_nmoves(i, j - b->size - 1) < ft_nmoves(t[0], t[1]))
		{
			t[0] = i;
			t[1] = j - b->size - 1;
		}
		tmp_b = tmp_b->prev;
		j--;
	}
}

void	move(t_stack *a, t_stack *b, int t[])
{
	int	m;

	m = ft_move(t);
	while (m != PA)
	{
		if (m == RA)
			rx(a, "ra");
		else if (m == RB)
			rx(b, "rb");
		else if (m == RR)
			rr(a, b, "rr");
		else if (m == RRA)
			rrx(a, "rra");
		else if (m == RRB)
			rrx(b, "rrb");
		else if (m == RRR)
			rrr(a, b, "rrr");
		m = ft_move(t);
	}
	px(b, a, "pa");
}

void	push_a(t_stack *a, t_stack *b)
{
	int		t[2];
	int		min;
	int		i;

	while (b->size > 0)
	{
		first_half(a, b, t);
		second_half(a, b, t);
		move(a, b, t);
	}
	i = stack_min(a, &min);
	while (a->head->nbr != min)
	{
		if (i <= ((a->size) / 2))
			rx(a, "ra");
		else
			(rrx(a, "rra"));
	}
}
