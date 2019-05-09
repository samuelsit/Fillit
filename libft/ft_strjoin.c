/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:47:47 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/08 18:43:29 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lenght;
	int		i;
	int		j;
	char	*str;

	if (s1 && s2)
	{
		lenght = ft_strlen(s1) + ft_strlen(s2);
		i = 0;
		j = 0;
		if (!(str = (char *)malloc(sizeof(char) * lenght + 1)))
			return (NULL);
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
