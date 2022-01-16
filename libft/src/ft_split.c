/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:54:02 by oaizab            #+#    #+#             */
/*   Updated: 2021/11/12 14:38:23 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nextword(const char *s, size_t *start, size_t *end, char c)
{
	size_t	i;

	if (!s[*end])
		return (0);
	i = *end;
	while (s[i] == c)
		i++;
	if (!s[i])
		return (0);
	*start = i;
	while (s[i] != c && s[i])
		i++;
	*end = i;
	return (1);
}

static size_t	wordcount(char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	count;

	start = 0;
	end = 0;
	count = 0;
	while (nextword(s, &start, &end, c))
		count++;
	return (count);
}

static void	cleari(char **tab, size_t i)
{
	while (i > 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab[0]);
	free(tab);
}

static int	filli(char **tab, char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*tmp;

	start = 0;
	end = 0;
	i = 0;
	while (nextword(s, &start, &end, c))
	{
		tmp = ft_substr(s, start, end - start);
		if (!tmp)
		{
			cleari(tab, i);
			return (0);
		}
		tab[i++] = tmp;
	}
	tab[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**tab;

	if (!s)
		return (NULL);
	i = wordcount(s, c);
	tab = (char **) malloc((i + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!filli(tab, s, c))
		return (NULL);
	return (tab);
}
