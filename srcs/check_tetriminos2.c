/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:09:57 by ssitruk           #+#    #+#             */
/*   Updated: 2019/05/14 16:11:07 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fillit.h"

int	cardinal(char **tet, int i, int j)
{
	printf("tet[%d][%d] : %c\n", i, j, tet[i][j]);
	return (1);
}

void	four_filled(char **tet)
{
	int i;
	int j;
	int i_filled;
	int j_filled;
	int nb_filled;

	i = 0;
	nb_filled = 0;
	while (tet[i])
	{
		j = 0;
		while (tet[i][j])
		{
			if (tet[i][j] == FILLED)
			{
				i_filled = i;
				j_filled = j;
				nb_filled++;
			}
			j++;
		}
		i++;
	}
	if (nb_filled != 4 || !cardinal(tet, i_filled, j_filled))
		exit(0);
}
