/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:43:07 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/05 16:55:22 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmps;

	tmps = (unsigned char *)s;
	while (n != 0)
	{
		if (*tmps != (unsigned char)c)
			tmps++;
		else
			return (tmps);
		n--;
	}
	return (NULL);
}
