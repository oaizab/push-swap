/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_addresse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:01:00 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 12:43:28 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(unsigned long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

static void	print_nb(unsigned long n, char *base)
{
	if (n > 15)
	{
		print_nb(n / 16, base);
		print_nb(n % 16, base);
	}
	else
	{
		ft_putchar(base[n]);
	}
}

int	ft_putnbr_addresse(unsigned long n, char *base)
{
	ft_putstr("0x");
	print_nb(n, base);
	return (getsize(n) + 2);
}
