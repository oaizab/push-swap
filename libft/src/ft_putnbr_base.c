/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:42:08 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 12:43:33 by oaizab           ###   ########.fr       */
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
		n = n / 16;
		size++;
	}
	return (size);
}

static void	print_nb(unsigned int n, char *base)
{
	if (n > 15)
	{
		print_nb(n / 16, base);
		print_nb(n % 16, base);
	}
	else
		ft_putchar(base[n]);
}

int	ft_putnbr_base(unsigned int n, char *base)
{
	print_nb(n, base);
	return (getsize(n));
}
