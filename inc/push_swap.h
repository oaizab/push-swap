/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:45:52 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/17 16:50:46 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

//
// Defining moves
//

# define PA 11
# define PB 12
# define SA 21
# define SB 22
# define SS 23
# define RA 31
# define RB 32
# define RR 33
# define RRA 41
# define RRB 42
# define RRR 43

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
void	ft_addlast(t_stack *s, int n);
int		ft_pop(t_stack *s);
void	ft_clear_stack(t_stack *stack);
void	push_b(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);
int		stack_min(t_stack *s, int *min);
int		stack_max(t_stack *s, int *max);
int		ft_move(int t[]);
int		ft_nmoves(int a, int b);

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
// Sorting functions
//

void	ft_sort(t_stack *a, t_stack *b);
void	lis(t_stack A);
int		ft_sorted(t_stack *a);

//
// Checker functions
//

void	check(t_stack *a, t_stack *b);

//
// Extra functions
//

void	ft_error(t_stack *s);
void	ft_memerr(void);
void	ft_freetab(char **tab, int i);
int		ft_parser(int ac, char *av[], int *tab[]);
int		ft_checkdup(int t[], int size);

#endif