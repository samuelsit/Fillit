/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:18:55 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/07 23:12:56 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		backslash(char *str)
{
	return ((*str == '\f') || (*str == '\t') ||
			(*str == '\n') || (*str == '\r') ||
			(*str == '\v') || (*str == ' '));
}

static	int		is_neg(int isneg, char *str)
{
	if (*str == '-')
		isneg = 1;
	return (isneg);
}

int				ft_atoi(const char *str)
{
	long long	nb;
	int			isneg;

	isneg = 0;
	nb = 0;
	while (backslash((char *)str))
		str++;
	isneg = is_neg(isneg, (char *)str);
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	if (isneg == 1)
		return ((int)-nb);
	else
		return ((int)nb);
}
