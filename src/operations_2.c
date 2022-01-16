/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:44:45 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 17:42:15 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_stack_before_last(t_stack *stack)
{
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void	ft_rrotate_a(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = ft_stack_before_last(*stack);
		tmp->next->next = *stack;
		*stack = tmp->next;
		tmp->next = NULL;
	}
}

void	ft_rrotate_ab(t_stack **stack_1, t_stack **stack_2)
{
	ft_rrotate_a(stack_1);
	ft_rrotate_a(stack_2);
}
