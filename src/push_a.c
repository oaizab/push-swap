/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:35:18 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/12 17:09:06 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nmoves(int a, int b)
{
	int	n;

	n = 0;
	if (a * b <= 0)
		return (ft_abs(a) + ft_abs(b) + 1);
	a = ft_abs(a);
	b = ft_abs(b);
	while (a > 0 && b > 0)
	{
		n++;
		a--;
		b--;
	}
	return (n + a + b + 1);
}

int	ft_move(int t[])
{
	if (t[0] == 0 && t[1] == 0)
		return (PA);
	else if (t[0] > 0)
	{
		t[0]--;
		if (t[1] > 0)
			return (t[1]--, RR);
		return (RA);
	}
	else if (t[0] < 0)
	{
		t[0]++;
		if (t[1] < 0)
			return (t[1]++, RRR);
		return (RRA);
	}
	else if (t[1] > 0)
		return (t[1]--, RB);
	t[1]++;
	return (RRB);
}

int	stack_max(t_stack *s, int *max)
{
	t_slist	*tmp;
	int		max_index;
	int		i;

	tmp = s->head;
	*max = tmp->nbr;
	i = 0;
	while (tmp)
	{
		i++;
		if (tmp->nbr < *max)
		{
			*max = tmp->nbr;
			max_index = i;
		}
		tmp = tmp->next;
	}
	return (max_index);
}

int	find_pose_a(t_stack *a, int n)
{
	t_slist	*tmp_a;
	int 	i;
	int		max;

	tmp_a = a->head;
	if (n < a->head->nbr && n > a->tail->nbr)
		return (0);
	i = 1;
	while (i < a->size / 2)
	{
		if (n > tmp_a->nbr && n < tmp_a->next->nbr)
			return (i);
		tmp_a = tmp_a->next;
		i++;
	}
	tmp_a = a->tail;
	i = a->size;
	while (i > a->size / 2)
	{
		if (n > tmp_a->prev->nbr && n < tmp_a->nbr)
			return (i - a->size - 1);
		tmp_a = tmp_a->prev;
		i--;
	}
	i = stack_max(a, &max);
	if (i < a->size /2)
		return (i - 1);
	return (i - a->size - 1);
}

void	best_move(t_stack *a, t_stack *b, int t[])
{
	int		i;
	int		j;
	t_slist	*tmp_b;

	tmp_b = b->head;
	j = 0;
	t[0] = find_pose_a(a, tmp_b->nbr);
	t[1] = 0;
	while (j < b->size / 2)
	{
		i = find_pose_a(a, tmp_b->nbr);
		if (ft_nmoves(i, j) < ft_nmoves(t[0], t[1]))
		{
			t[0] = i;
			t[1] = j;
		}
		tmp_b = tmp_b->next;
		j++;
	}
	tmp_b = b->tail;
	j = b->size;
	while (j > b->size / 2)
	{
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

void	push_a(t_stack *a, t_stack *b)
{
	int		t[2];
	int		m;

	while (b->size > 0)
	{
		best_move(a, b, t);
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
}
