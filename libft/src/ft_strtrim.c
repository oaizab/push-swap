/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:54:50 by oaizab            #+#    #+#             */
/*   Updated: 2021/11/14 20:07:07 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isin(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	skipfirst(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && isin(s1[i], set))
		i++;
	return (i);
}

static size_t	skiplast(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (isin(s1[i], set) && i > 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = skipfirst(s1, set);
	j = skiplast(s1, set);
	if (i > j)
		return (ft_substr(s1, i, 0));
	return (ft_substr(s1, i, j - i + 1));
}
