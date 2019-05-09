/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:47:07 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/24 18:04:13 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int c)
{
	char	*tab;

	if (!(tab = ft_strjoin(s1, s2)))
		return (NULL);
	if (c == 1 && s1)
		free(s1);
	if (c == 2 && s2)
		free(s2);
	if (c == 3 && s1 && s2)
	{
		free(s1);
		free(s2);
	}
	return (tab);
}
