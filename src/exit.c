/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:09:42 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/16 14:35:28 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freetab(char **tab, int i)
{
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
}

void	ft_memerr(void)
{
	ft_printf("Can't allocate memory.\n");
	exit(1);
}

void	ft_error(t_stack *s)
{
	if (s)
	{
		ft_clear_stack(s);
		free(s);
	}
	ft_putendl_fd("Error", 2);
	exit(1);
}
