/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 01:06:48 by ssitruk           #+#    #+#             */
/*   Updated: 2019/06/08 01:09:06 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	clear_field(t_map *map, char c)
{
	int i;
	int j;

	i = 0;
	while (map->field[i])
	{
		j = 0;
		while (map->field[i][j])
		{
			if (map->field[i][j] == c)
				map->field[i][j] = EMPTY;
			j++;
		}
		i++;
	}
}

int		put_in_field(t_map *map, t_tetris *tetris, int x, int y)
{
	int i;
	int j;

	i = 0;
	if (tetris->width + x > map->size || tetris->height + y > map->size)
		return (0);
	while (tetris->elem[i])
	{
		j = 0;
		while (tetris->elem[i][j])
		{
			if (map->field[y + i][x + j] != EMPTY
					&& tetris->elem[i][j] == FILLED)
			{
				clear_field(map, map->nb_tetris + 65);
				return (0);
			}
			if (tetris->elem[i][j] == FILLED)
				map->field[y + i][x + j] = (char)(map->nb_tetris + 65);
			j++;
		}
		i++;
	}
	map->nb_tetris++;
	return (1);
}

t_map	*backtracking(t_map *map, t_list *list)
{
	t_map	*ret;
	int		x;
	int		y;

	if (!list)
		return (map);
	x = 0;
	y = 0;
	while (y < map->size)
	{
		while (x < map->size)
		{
			if ((put_in_field(map, list->content, x, y)))
			{
				if ((ret = backtracking(map, list->next)))
					return (ret);
				map->nb_tetris--;
				clear_field(map, map->nb_tetris + 65);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (NULL);
}
