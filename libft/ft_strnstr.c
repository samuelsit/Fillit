/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:58:07 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/05 12:12:00 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	if (!needle[i])
		return ((char *)&haystack[i]);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && needle[j] == haystack[i + j]
				&& (i + j) < (int)len)
		{
			j++;
			if (!needle[j])
			{
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
