/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:37:42 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 12:43:37 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	print_nb(unsigned int n)
{
	if (n > 9)
	{
		print_nb(n / 10);
		print_nb(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	ft_putnbr_unsigned(unsigned int n)
{
	print_nb(n);
	return (getsize(n));
}
