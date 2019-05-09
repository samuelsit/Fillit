/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:06:53 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/08 18:17:06 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		lenght;
	char	*str;

	i = 0;
	if (s)
	{
		lenght = ft_strlen(s);
		if (!(str = (char *)malloc(sizeof(char) * lenght + 1)))
			return (NULL);
		while (i < lenght)
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
