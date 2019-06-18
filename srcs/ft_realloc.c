/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 01:22:04 by ssitruk           #+#    #+#             */
/*   Updated: 2019/06/18 01:13:14 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	*ft_realloc(void *ptr, size_t len, size_t first)
{
	void	*real;

	if (!(real = malloc(len)))
		return (NULL);
	ft_memset(real, 0, len);
	if (real)
		ft_memcpy_fillit(real, ptr + first, len);
	free(ptr);
	return (real);
}
