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

void	print_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	**create_map(char **map, int size_map)
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

char	**malloc_map(int size_map)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * size_map + 1)))
		put_error();
	while (i < size_map)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * size_map + 1)))
			put_error();
		map[i][size_map] = '\0';
		i++;
	}
	map[i] = NULL;
	map = create_map(map, size_map);
	return (map);
}
