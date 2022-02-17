/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:43:37 by oaizab            #+#    #+#             */
/*   Updated: 2021/11/09 15:20:06 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start < size)
	{
		if (start + len > size)
			len = size - start;
		str = (char *) malloc((len + 1) * sizeof (char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s + start, len + 1);
	}
	else
	{
		str = (char *) malloc(sizeof (char));
		if (!str)
			return (NULL);
		str[0] = 0;
	}
	return (str);
}
