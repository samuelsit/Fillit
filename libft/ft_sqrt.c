/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:57:00 by ssitruk           #+#    #+#             */
/*   Updated: 2019/05/21 10:46:00 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(float nb)
{
	float	x;
	float	y;
	float	e;

	x = nb;
	y = 1;
	e = 0.000001;
	while (x - y > e)
	{
		x = (x + y) / 2;
		y = nb / x;
	}
	return (x);
}
