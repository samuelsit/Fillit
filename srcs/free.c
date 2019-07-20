/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 01:09:47 by ssitruk           #+#    #+#             */
/*   Updated: 2019/07/03 10:45:12 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (i < map->size)
	{
		free(map->field[i]);
		i++;
	}
	free(map->field);
	free(map);
	map = NULL;
}

void	free_array(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_tetris(t_tetris *tetris)
{
	int i;

	i = 0;
	if (!tetris)
		return ;
	while (i < tetris->height)
	{
		free(tetris->elem[i]);
		i++;
	}
	free(tetris->elem);
	free(tetris);
	tetris = NULL;
}

void	free_list(t_list *list)
{
	t_list *tmp;

	if (list)
		tmp = list->next;
	while (list)
	{
		free_tetris(list->content);
		free(list);
		list = tmp;
		if (list)
			tmp = tmp->next;
	}
	list = NULL;
}
