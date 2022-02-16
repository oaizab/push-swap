/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:08:41 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/16 16:54:21 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi_i(char **tab, int k)
{
	long	nb;
	int		i;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (tab[k][0] && tab[k][0] == '+' && tab[k][1])
		i++;
	if (tab[k][0] && tab[k][0] == '-' && tab[k][1])
	{
		sign = -1;
		i++;
	}
	while (tab[k][i])
	{
		if ((tab[k][i] >= '0' && tab[k][i] <= '9') && \
			((nb < 2147483647 && sign > 0) || (nb < 2147483648 && sign < 0)))
			nb = nb * 10 + (tab[k][i++] - '0');
		else
			(ft_freetab(tab, k), ft_error(NULL));
	}
	return (nb * sign);
}

char	**ft_get_args(char **tab, int l)
{
	char	*str;
	char	*tmp;
	char	**args;
	int		i;

	i = 1;
	str = NULL;
	while (i < l)
	{
		tmp = str;
		str = ft_strjoin(str, tab[i]);
		if (tmp)
			free(tmp);
		if (!str)
			ft_memerr();
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		if (!str)
			ft_memerr();
		i++;
	}
	args = ft_split(str, ' ');
	free(str);
	if (!args)
		ft_memerr();
	return (args);
}

int	ft_parser(int ac, char *av[], int *tab[])
{
	char	**args;
	int		size;
	int		i;

	args = ft_get_args(av, ac);
	i = 0;
	size = 0;
	while (args[size])
		size++;
	*tab = ft_calloc(size, sizeof(int));
	if (!*tab)
		(ft_freetab(args, 0), ft_memerr());
	while (i < size)
	{
		(*tab)[i] = ft_atoi_i(args, i);
		free(args[i++]);
	}
	free(args);
	return (size);
}

int	ft_checkdup(int t[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (t[i] == t[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
