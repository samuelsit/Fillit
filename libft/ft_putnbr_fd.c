/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:48:35 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/04 11:50:46 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int unit;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = -147483648;
		}
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + 48, fd);
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		unit = n % 10;
		ft_putchar_fd(unit + 48, fd);
	}
}
