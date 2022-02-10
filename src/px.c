/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:31:36 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/10 13:50:31 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack *from, t_stack *to, char *msg)
{
	int	n;

	if (from->size == 0)
		return ;
	n = ft_pop(from);
	ft_push(to, n);
	if (msg)
		ft_printf("%s\n", msg);
}
