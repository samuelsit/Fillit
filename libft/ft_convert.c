/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:48:57 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/10 18:00:10 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		index_base(char nbr, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == nbr)
			return (i);
		i++;
	}
	return (0);
}

static char		*base10_to_base(int base10, char *base, char *value)
{
	unsigned int	b10;
	int				blen;
	int				i;

	b10 = (base10 < 0 ? -base10 : base10);
	blen = ft_strlen(base);
	i = 0;
	if (b10 == 0)
	{
		value[0] = '0';
		i++;
	}
	while (b10 != 0)
	{
		value[i] = base[b10 % blen];
		b10 /= blen;
		i++;
	}
	if (base10 < 0)
	{
		value[i] = '-';
		i++;
	}
	value[i] = '\0';
	return (value);
}

static int		base_to_base10(char *nbr, char *base)
{
	int blen;
	int nlen;
	int value;
	int power;

	blen = ft_strlen(base);
	nlen = ft_strlen(nbr) - 1;
	value = 0;
	power = 1;
	while (nbr[0] == '-' || nbr[0] == '+' ? nlen > 0 : nlen >= 0)
	{
		value += index_base(nbr[nlen], base) * power;
		power *= blen;
		nlen--;
	}
	if (nbr[0] == '-')
		return (-value);
	else
		return (value);
}

char			*ft_convert(char *nbr, char *base_from, char *base_to)
{
	int		value;
	char	*base;
	int		size;
	int		search;
	char	letter;

	base = malloc(sizeof(char) * 33);
	value = base_to_base10(nbr, base_from);
	base = base10_to_base(value, base_to, base);
	size = 0;
	search = 0;
	while (base[size] != '\0')
		size++;
	size--;
	while (size > search)
	{
		letter = base[search];
		base[search] = base[size];
		base[size] = letter;
		size--;
		search++;
	}
	return (base);
}
