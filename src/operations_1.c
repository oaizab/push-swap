/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:44:27 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 17:22:54 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack **stack)
{
	int	a;
	int	b;

	if (*stack && (*stack)->next)
	{
		a = ft_pop(stack);
		b = ft_pop(stack);
		ft_push(stack, a);
		ft_push(stack, b);
	}
}

void	ft_swap_ab(t_stack **stack_1, t_stack **stack_2)
{
	ft_swap_a(stack_1);
	ft_swap_a(stack_2);
}

void	ft_push_a(t_stack **stack_1, t_stack **stack_2)
{
	int	a;

	if (*stack_2)
	{
		a = ft_pop(stack_2);
		ft_push(stack_1, a);
	}
}
