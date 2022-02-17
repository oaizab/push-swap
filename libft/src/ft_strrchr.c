/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:15:08 by oaizab            #+#    #+#             */
/*   Updated: 2021/11/06 21:47:58 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	if (i)
		i--;
	while (i > 0)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i--;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (NULL);
}
