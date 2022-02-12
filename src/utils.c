/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:11:45 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/13 14:58:09 by oaizab           ###   ########.fr       */
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

void	ft_show(t_stack a, t_stack b)
{
	int	i;

	i = ft_max(a.size, b.size);
	printf("=======\n");
	while (i > 0)
	{
		if (a.size >= i)
		{
			printf("%3d ", a.head->nbr);
			a.head = a.head->next;
		}
		else
			printf("    ");
		if (b.size >= i)
		{
			printf("%3d\n", b.head->nbr);
			b.head = b.head->next;
		}
		else
			printf("   \n");
		i--;
	}
	printf("___ ___\n");
	printf("  a   b\n");
}
