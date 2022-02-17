/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:23:34 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/16 12:43:17 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_check(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, const char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789abcdef"));
	if (c == 'p')
		return (ft_putnbr_addresse(va_arg(ap, long), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
