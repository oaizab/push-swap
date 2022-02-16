/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:11:45 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/14 14:26:51 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int	ft_nmoves(int a, int b)
{
	int	n;

	n = 0;
	if (a * b <= 0)
		return (ft_abs(a) + ft_abs(b) + 1);
	a = ft_abs(a);
	b = ft_abs(b);
	return (ft_max(a, b) + 1);
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

void	ft_clear_stack(t_stack *s)
{
	while (s->size > 0)
	{
		ft_pop(s);
	}
}
