/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:13:16 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 16:55:58 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int nbr)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

void	ft_push(t_stack **stack, int nbr)
{
	t_stack	*new;

	new = ft_new_node(nbr);
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

int	ft_pop(t_stack **stack)
{
	t_stack	*tmp;
	int		nbr;

	tmp = *stack;
	*stack = (*stack)->next;
	nbr = tmp->nbr;
	free(tmp);
	return (nbr);
}

void	ft_clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

int	ft_isempti(t_stack *stack)
{
	return (stack == NULL);
}
