/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 01:09:47 by ssitruk           #+#    #+#             */
/*   Updated: 2019/06/18 02:33:17 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		is_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == FILLED)
			return (0);
		i++;
	}
	return (1);
}

void	free_before_realloc(t_tetris *tetris)
{
	int i;

	i = 0;
	while (tetris->elem[i])
	{
		if (is_empty_line(tetris->elem[i]))
			free(tetris->elem[i]);
		i++;
	}
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (i < map->size + 1)
	{
		free(map->field[i]);
		i++;
	}
	free(map->field);
	free(map);
	map = NULL;
}

void	free_tetris(t_tetris *tetris)
{
	int i;

	i = 0;
	if (!tetris)
		return ;
	while (i < tetris->height + 1)
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
		if (tmp)
			tmp = tmp->next;
	}
	list = NULL;
}
