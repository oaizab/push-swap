/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:03:49 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/16 19:33:23 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*t;
	int		size;

	if (argc == 1)
		return (0);
	t = NULL;
	size = ft_parser(argc, argv, &t);
	if (ft_checkdup(t, size))
		(free(t), ft_error(NULL));
	a = ft_stack();
	while (size > 0)
	{
		ft_push(a, t[size - 1]);
		size--;
	}
	free(t);
	b = ft_stack();
	ft_sort(a, b);
	(ft_clear_stack(a), free(a));
	(ft_clear_stack(b), free(b));
	return (0);
}
