/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:41:26 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/17 17:22:29 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cmd(char *str)
{
	int		cmd;

	if (ft_strncmp(str, "pa\n", 10) == 0)
		cmd = PA;
	else if (ft_strncmp(str, "pb\n", 10) == 0)
		cmd = PB;
	else if (ft_strncmp(str, "ra\n", 10) == 0)
		cmd = RA;
	else if (ft_strncmp(str, "rb\n", 10) == 0)
		cmd = RB;
	else if (ft_strncmp(str, "rr\n", 10) == 0)
		cmd = RR;
	else if (ft_strncmp(str, "rra\n", 10) == 0)
		cmd = RRA;
	else if (ft_strncmp(str, "rrb\n", 10) == 0)
		cmd = RRB;
	else if (ft_strncmp(str, "rrr\n", 10) == 0)
		cmd = RRR;
	else if (ft_strncmp(str, "sa\n", 10) == 0)
		cmd = SA;
	else if (ft_strncmp(str, "sb\n", 10) == 0)
		cmd = SB;
	else if (ft_strncmp(str, "ss\n", 10) == 0)
		cmd = SS;
	else
		cmd = -1;
	return (cmd);
}

void	do_cmd(t_stack *a, t_stack *b, int cmd)
{
	if (cmd == PA)
		px(b, a, NULL);
	else if (cmd == PB)
		px(a, b, NULL);
	else if (cmd == RA)
		rx(a, NULL);
	else if (cmd == RB)
		rx(b, NULL);
	else if (cmd == RR)
		rr(a, b, NULL);
	else if (cmd == RRA)
		rrx(a, NULL);
	else if (cmd == RRB)
		rrx(b, NULL);
	else if (cmd == RRR)
		rrr(a, b, NULL);
	else if (cmd == SA)
		sx(a, NULL);
	else if (cmd == SB)
		sx(b, NULL);
	else if (cmd == SS)
		ss(a, b, NULL);
}

void	check(t_stack *a, t_stack *b)
{
	char	*str;
	int		cmd;

	str = get_next_line(0);
	while (str)
	{
		cmd = get_cmd(str);
		free(str);
		if (cmd == -1)
		{
			(ft_clear_stack(b), free(b));
			ft_error(a);
		}
		do_cmd(a, b, cmd);
		str = get_next_line(0);
	}
	if (b->size == 0 && ft_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
