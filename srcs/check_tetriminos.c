/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:00:04 by ssitruk           #+#    #+#             */
/*   Updated: 2019/07/03 11:41:05 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_char(char *str, int l)
{
	int i;

	i = 0;
	if ((l % 5) != 0)
	{
		while (str[i] != '\0')
		{
			if (str[i] != EMPTY && str[i] != FILLED)
				return (0);
			i++;
		}
	}
	return (1);
}

int		column(int c, int l)
{
	if ((l % 5) != 0)
	{
		if (c != 4)
			return (0);
	}
	else
	{
		if (c != 0)
			return (0);
	}
	return (1);
}

int		line(int l)
{
	if ((l % 5) == 0)
		return (1);
	return (0);
}

int		check_tet(int fd)
{
	int		ret;
	int		c;
	int		l;
	char	*line_tet;

	l = 1;
	while ((ret = get_next_line(fd, &line_tet)) > 0)
	{
		if (!(check_char(line_tet, l)))
			put_error();
		c = ft_strlen(line_tet);
		if (!(column(c, l)))
			put_error();
		l++;
		if (line_tet)
		{
			free(line_tet);
			line_tet = NULL;
		}
	}
	free(line_tet);
	if (!(line(l)))
		put_error();
	return (1);
}

int		apply_on_list(t_list *list)
{
	t_tetris	*tetris;
	t_list		*tmp;
	int			nb_tetris;

	tmp = list;
	nb_tetris = 0;
	while (tmp)
	{
		tetris = tmp->content;
		tetris->occurence = four_filled(tetris->elem);
		tmp = tmp->next;
		nb_tetris++;
	}
	if (nb_tetris > 26)
		put_error();
	return (nb_tetris);
}
