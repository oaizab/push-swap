/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:16:45 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 12:39:08 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		size;

	va_start(ap, s);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			size += ft_printf_check(s[i], ap);
		}
		else
			size += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (size);
}
