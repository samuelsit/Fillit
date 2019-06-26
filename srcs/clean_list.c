/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 01:10:02 by ssitruk           #+#    #+#             */
/*   Updated: 2019/06/18 02:33:20 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			filled_in_width(char *elem)
{
	int height;
	int nb;

	height = 0;
	nb = 0;
	while (elem[height])
	{
		if (elem[height] == FILLED)
			nb++;
		height++;
	}
	return (nb);
}

int			get_width(char **elem, int occur, int height)
{
	int width;
	int new_width;

	width = 0;
	new_width = 0;
	while (elem[width])
	{
		new_width = filled_in_width(elem[width]) > new_width
		? filled_in_width(elem[width]) : new_width;
		width++;
	}
	if (new_width == 2 && occur != 8 && height < 3)
		new_width++;
	return (new_width);
}

int			get_height(char **elem)
{
	int height;
	int width;
	int new_height;

	height = 0;
	width = 0;
	new_height = 0;
	while (elem[height])
	{
		width = 0;
		while (elem[height][width])
		{
			if (elem[height][width] == FILLED)
			{
				new_height++;
				break ;
			}
			width++;
		}
		height++;
	}
	return (new_height);
}

#include<stdio.h>

char	**new_malloc(t_tetris *tetris)
{
	int		i;
	int		first_filled_height;
	int		first_filled_width;
	char	**new;

	i = 0;
	if (!(new = malloc(sizeof(char*) * (tetris->height + 1))))
		return (NULL);
	while (i < tetris->height + 1)
	{
		if (!(new[i] = malloc(sizeof(char) * (tetris->width + 1))))
			return (NULL);
		new[i][tetris->width] = '\0';
		i++;
	}
	new[i] = NULL;
	i = 0;
	first_filled_height = len_height_filled(tetris->elem);
	first_filled_width = len_width_filled(tetris->elem);
	while (i < tetris->height)
	{
		new[i] = ft_strncpy_f(new[i], tetris->elem[first_filled_height + i], first_filled_width, tetris->width);
		i++;
		new[i][tetris->width] = '\0';
	}
	new[i] = NULL;
	return (new);
}

void	clean_list(t_list **list)
{
	t_tetris	*tetris;
	t_list		*tmp;

	tmp = *list;
	tetris = NULL;
	while (tmp)
	{
		tetris = tmp->content;
		tetris->height = get_height(tetris->elem);
		tetris->width = get_width(tetris->elem, tetris->occurence,
			tetris->height);
		tetris->elem = new_malloc(tetris);
		tmp = tmp->next;
	}
}
