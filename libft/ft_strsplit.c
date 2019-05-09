/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:03:08 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/10 18:16:45 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(const char *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	if (s[0] != '\0')
		words++;
	return (words);
}

static void		init(size_t *i, size_t *k)
{
	*i = 0;
	*k = 0;
}

static char		**free_tab(char **tab, size_t k)
{
	while (k)
	{
		free(tab[k]);
		k--;
	}
	free(tab);
	return (NULL);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	k;
	int		fi;
	int		la;
	char	**tab;

	tab = NULL;
	init(&i, &k);
	if (s && (tab = (char **)malloc(sizeof(char *) * (count(s, c) + 1))))
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			fi = i;
			while (s[i] && s[i] != c)
				i++;
			la = i;
			if (la > fi)
				if (!(tab[k++] = ft_strsub(s, fi, (la - fi))))
					return (free_tab(tab, k));
		}
		tab[k] = NULL;
	}
	return (tab);
}
