/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:11:45 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/12 13:42:31 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
