/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:03:48 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 12:43:41 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	print_nb(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		print_nb(-1 * n);
	}
	else if (n > 9)
	{
		print_nb(n / 10);
		print_nb(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	ft_putnbr(int n)
{
	print_nb(n);
	return (getsize(n));
}
