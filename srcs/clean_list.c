/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 01:10:02 by ssitruk           #+#    #+#             */
/*   Updated: 2019/06/08 01:20:11 by ssitruk          ###   ########.fr       */
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

t_tetris	*new_malloc(t_tetris *tetris)
{
	int		i;
	int		first_filled_height;
	int		first_filled_width;

	i = 0;
	first_filled_height = len_height_filled(tetris->elem);
	first_filled_width = len_width_filled(tetris->elem);
	while (i < tetris->height)
	{
		if (!(tetris->elem[i] =
				(char *)ft_realloc(tetris->elem[i + first_filled_height],
				sizeof(char) * (tetris->width + 1), first_filled_width)))
			return (NULL);
		tetris->elem[i][tetris->width] = '\0';
		i++;
	}
	tetris->elem[i] = NULL;
	return (tetris);
}

t_list		*clean_list(t_list *list)
{
	t_tetris	*tetris;
	t_list		*tmp;

	tmp = list;
	tetris = NULL;
	while (tmp)
	{
		tetris = tmp->content;
		tetris->height = get_height(tetris->elem);
		tetris->width = get_width(tetris->elem, tetris->occurence,
			tetris->height);
		tetris = new_malloc(tetris);
		tmp = tmp->next;
	}
	return (list);
}
