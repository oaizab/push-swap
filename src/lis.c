/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:08:49 by oaizab            #+#    #+#             */
/*   Updated: 2022/02/10 10:35:00 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ones(int t[], int l)
{
	int	i;

	i = 0;
	while (i < l)
		t[i++] = 1;
}

int	ft_maxi(int t[], int len)
{
	int	i;
	int	max;

	i = len;
	max = len - 1;
	while (--i >= 0)
	{
		if (t[i] > t[max])
			max = i;
	}
	return (max);
}

int	*ft_fill(t_slist *lst, int size)
{
	int	*arr;
	int	i;

	arr = ft_calloc(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		arr[i++] = lst->nbr;
		lst = lst->next;
	}
	return (arr);
}

void	fill_keeps(t_stack A, int *arr, int *length, int *sub)
{
	int		i;
	int		j;
	t_slist	*tmp;

	i = ft_maxi(length, A.size);
	tmp = A.tail;
	j = length[i] +1;
	while (--j > 0)
	{
		while (tmp->nbr != arr[i])
			tmp = tmp->prev;
		tmp->keep_in_a = 1;
		i = sub[i];
	}
}

// longest increasing subsequence

void	lis(t_stack A)
{
	int	*arr;
	int	*length;
	int	*sub;
	int	i;
	int	j;

	arr = ft_fill(A.head, A.size);
	length = ft_calloc(A.size, sizeof(int));
	sub = ft_calloc(A.size, sizeof(int));
	ft_ones(length, A.size);
	i = 0;
	while (++i < A.size)
	{
		j = -1;
		while (++j < i)
		{
			if ((arr[j] < arr[i]) && (length[j] + 1 >= length[i]))
			{
					length[i] = length[j] + 1;
					sub[i] = j;
			}
		}
	}
	fill_keeps(A, arr, length, sub);
}
