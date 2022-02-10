/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:45:52 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/10 13:53:27 by oaizab           ###   ########.fr       */
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

typedef struct s_slist
{
	int				nbr;
	int				keep_in_a;
	struct s_slist	*next;
	struct s_slist	*prev;
}				t_slist;

typedef struct s_stack
{
	t_slist	*head;
	t_slist	*tail;
	int		size;
}				t_stack;

//
// Stack manupilation functions
//

t_stack	*ft_stack(void);
void	ft_push(t_stack *stack, int nbr);
int		ft_pop(t_stack *s);
void	ft_clear_stack(t_stack **stack);
int		ft_top(t_stack *stack);
void	ft_show(t_stack a, t_stack b);
void	push_b(t_stack *a, t_stack *b);

//
// Stack operation functions
//

void	sx(t_stack *s, char *msg);
void	ss(t_stack *a, t_stack *b, char *msg);
void	px(t_stack *from, t_stack *to, char *msg);
void	rx(t_stack *s, char *msg);
void	rr(t_stack *a, t_stack *b, char *msg);
void	rrx(t_stack *s, char *msg);
void	rrr(t_stack *a, t_stack *b, char *msg);

//
// Sorting function
//

void	ft_sort(t_stack **stack_1, t_stack **stack_2);
void	lis(t_stack A);

#endif