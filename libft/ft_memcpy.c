/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:44:34 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/05 14:13:47 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*tmpdst;
	char	*tmpsrc;

	i = 0;
	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	while (i != (int)n)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (dst);
}
