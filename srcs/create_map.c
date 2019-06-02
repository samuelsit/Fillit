/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:03:36 by ssitruk           #+#    #+#             */
/*   Updated: 2019/05/21 13:27:16 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->field[i])
	{
		j = 0;
		while (map->field[i][j])
		{
			ft_putchar(map->field[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	**init_map(char **map, int size_map)
{
	int i;
	int j;

	i = 0;
	while (i < size_map)
	{
		j = 0;
		while (j < size_map)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

t_map	*create_map(int size)
{
	t_map	*map;
	int		i;

	i = 0;
	if (!(map = malloc(sizeof(*map))))
		put_error();
	if (!(map->field = (char **)malloc(sizeof(char *) * (size + 1))))
		put_error();
	while (i < size)
	{
		if (!(map->field[i] = (char *)malloc(sizeof(char) * (size + 1))))
			put_error();
		map->field[i][size] = '\0';
		i++;
	}
	map->field[i] = NULL;
	map->field = init_map(map->field, size);
	map->size = size;
	map->nb_tetris = 0;
	return (map);
}
