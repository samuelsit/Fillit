/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:02:43 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/04 12:38:36 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	tmpc;
	char			*tmpb;

	i = 0;
	tmpc = (unsigned char)c;
	tmpb = (char *)b;
	while (i < (int)len)
	{
		tmpb[i] = tmpc;
		i++;
	}
	return (tmpb);
}
