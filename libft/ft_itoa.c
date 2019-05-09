/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:58:59 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/08 19:21:13 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_char(int number)
{
	int nb_number;

	nb_number = 1;
	while (number != 0)
	{
		number /= 10;
		nb_number++;
	}
	return (nb_number);
}

static void		init_neg(int *size, int *i, int *neg, int *n)
{
	*size = nb_char(*n);
	*i = 0;
	*neg = 0;
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

static int		min_val(int *i, int *n, char **str)
{
	if (*n == -2147483648)
	{
		*str[*i] = '8';
		*n = 214748364;
		return (1);
	}
	return (0);
}

char			*ft_itoa(int n)
{
	int		i;
	int		neg;
	char	*str;
	int		size;

	init_neg(&size, &i, &neg, &n);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (min_val(&i, &n, &str) == 1)
		i++;
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (n != 0)
	{
		str[i++] = (n % 10) + 48;
		n /= 10;
	}
	if (neg == 1)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
