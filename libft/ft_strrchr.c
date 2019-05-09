/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:55:22 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/07 23:13:16 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	int			ret;
	const char	*tmp;

	i = 0;
	ret = -1;
	tmp = s;
	while (*tmp)
		tmp++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ret = i;
		i++;
	}
	if (c == '\0')
		return ((char *)tmp);
	if (ret != -1)
		return ((char *)&s[ret]);
	return (NULL);
}
