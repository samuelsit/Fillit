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

/*
int	cardinal(char **tet, int i, int j)
{
	printf("tet[%d][%d] : %c\n", i, j, tet[i][j]);
	return (1);
}
*/

int	check_filled(char **tet, int i, int j)
{
	if (j + 1 < SIZE_TETRIS && tet[i][j + 1] == FILLED)
		return (1);
	if (j - 1 >= 0 && tet[i][j - 1] == FILLED)
		return (1);
	if (i + 1 < SIZE_TETRIS && tet[i + 1][j] == FILLED)
		return (1);
	if (i - 1 >= 0 && tet[i - 1][j] == FILLED)
		return (1);
	return (0);
}

void	four_filled(char **tet)
{
	int i;
	int j;
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
				if (!check_filled(tet, i, j))
					exit(0);
				nb_filled++;
			}
			j++;
		}
		i++;
	}
	if (nb_filled != 4)
		exit(0);;
}
