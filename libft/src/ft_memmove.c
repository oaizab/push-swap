/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:13:17 by oaizab            #+#    #+#             */
/*   Updated: 2021/11/06 18:55:56 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (len)
	{
		if (src - dst < 0)
		{
			i = len - 1;
			while (i > 0)
			{
				((char *) dst)[i] = ((const char *) src)[i];
				i--;
			}
			((char *) dst)[i] = ((const char *) src)[i];
		}
		else
		{
			return (ft_memcpy(dst, src, len));
		}
	}
	return (dst);
}
