/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:45:41 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 17:39:02 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_stack_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_rotate_a(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = tmp->next;
		ft_stack_last(tmp)->next = tmp;
		tmp->next = NULL;
	}
}

void	ft_rotate_ab(t_stack **stack_1, t_stack **stack_2)
{
	ft_rotate_a(stack_1);
	ft_rotate_a(stack_2);
}
