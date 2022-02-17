/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:04:05 by oaizab            #+#    #+#             */
/*   Updated: 2021/11/08 12:25:57 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	testlong(unsigned long long nbr, int sign)
{
	unsigned long long	ll;

	ll = 9223372036854775807;
	if (nbr >= (ll + 1) && sign == -1)
		return (0);
	if (nbr >= ll && sign == 1)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	nbr;
	size_t				i;
	int					sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - '0');
		if (testlong(nbr, sign) != 1)
			return (testlong(nbr, sign));
		i++;
	}
	return (sign * nbr);
}
