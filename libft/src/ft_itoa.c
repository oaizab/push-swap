/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:00:29 by oaizab            #+#    #+#             */
/*   Updated: 2021/11/09 21:04:40 by oaizab           ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	int				size;
	char			*nbr;
	unsigned int	nb;

	size = getsize(n);
	nbr = (char *) malloc((size + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[size] = '\0';
	size--;
	if (n < 0)
	{
		nb = n * -1;
		nbr[0] = '-';
	}
	else
		nb = n;
	if (n == 0)
		nbr[0] = '0';
	while (nb > 0)
	{
		nbr[size--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (nbr);
}
