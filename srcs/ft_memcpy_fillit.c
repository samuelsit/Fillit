/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_fillit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 01:21:29 by ssitruk           #+#    #+#             */
/*   Updated: 2019/06/08 01:23:40 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	*ft_memcpy_fillit(void *dst, const void *src, size_t end)
{
	size_t	i;
	char	*tmpdst;
	char	*tmpsrc;

	i = 0;
	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	while (i != end)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (dst);
}
