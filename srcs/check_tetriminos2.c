/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:09:57 by ssitruk           #+#    #+#             */
/*   Updated: 2019/05/15 15:00:34 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	put_error()
{
	ft_putstr("error\n");
	exit(0);
}

int	check_filled(char **tet, int i, int j, int occurence)
{
	if (j + 1 < SIZE_TETRIS && tet[i][j + 1] == FILLED)
		occurence++;
	if (j - 1 >= 0 && tet[i][j - 1] == FILLED)
		occurence++;
	if (i + 1 < SIZE_TETRIS && tet[i + 1][j] == FILLED)
		occurence++;
	if (i - 1 >= 0 && tet[i - 1][j] == FILLED)
		occurence++;
	return (occurence);
}

void	four_filled(char **tet)
{
	int i;
	int j;
	int nb_filled;
	int occurence;

	i = 0;
	nb_filled = 0;
	occurence = 0;
	while (tet[i])
	{
		j = 0;
		while (tet[i][j])
		{
			if (tet[i][j] == FILLED)
			{
				occurence = check_filled(tet, i, j, occurence);
				nb_filled++;
			}
			j++;
		}
		i++;
	}
	if ((occurence != 6 && occurence != 8) || nb_filled != 4)
		put_error();
}
