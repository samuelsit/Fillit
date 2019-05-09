/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:18:20 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/08 18:42:14 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				lenght;
	char			*str;

	i = 0;
	if (s)
	{
		lenght = ft_strlen(s);
		if (!(str = (char *)malloc(sizeof(char) * lenght + 1)))
			return (NULL);
		while (i < (unsigned int)lenght)
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
