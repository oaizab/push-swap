/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:06:02 by oaizab            #+#    #+#             */
/*   Updated: 2021/11/07 20:23:35 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((((char *) s1)[i] == ((char *)s2)[i]) && i < n - 1)
		i++;
	return ((unsigned char)((char *) s1)[i] - (unsigned char)((char *) s2)[i]);
}
