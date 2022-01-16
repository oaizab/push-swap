/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:45:52 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 17:24:30 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

//
// Defining structures
//

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}				t_stack;

//
// Stack manupilation functions
//

t_stack	*ft_new_node(int nbr);
void	ft_push(t_stack **stack, int nbr);
int		ft_pop(t_stack **stack);
void	ft_clear_stack(t_stack **stack);
int		ft_isempti(t_stack *stack);

//
// Stack operation functions
//

void	ft_swap_a(t_stack **stack);
void	ft_swap_ab(t_stack **stack_1, t_stack **stack_2);
void	ft_push_a(t_stack **stack_1, t_stack **stack_2);
void	ft_rotate_a(t_stack **stack);
void	ft_rrotate_a(t_stack **stack);
void	ft_rotate_ab(t_stack **stack_1, t_stack **stack_2);
void	ft_rrotate_ab(t_stack **stack_1, t_stack **stack_2);

#endif