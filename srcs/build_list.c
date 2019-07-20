/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:27:02 by ssitruk           #+#    #+#             */
/*   Updated: 2019/07/03 14:24:09 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	feed_tetris(int *i, t_tetris **tetris, char *line)
{
	if ((*i % 5) == 0)
		*tetris = new_tetris(SIZE_TETRIS, SIZE_TETRIS);
	ft_strcpy((*tetris)->elem[*i], line);
	free(line);
	line = NULL;
	(*i)++;
}

void	free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	feed_list(char *line, t_tetris *tetris, t_list **list, t_list **tmp)
{
	if (line)
		free_ptr(line);
	if (!(*list))
	{
		*list = lst_tetris(tetris, sizeof(*tetris));
		*tmp = *list;
	}
	else
	{
		(*tmp)->next = lst_tetris(tetris, sizeof(*tetris));
		*tmp = (*tmp)->next;
	}
}

void	build_list(int fd, t_list **list, t_tetris *tetris, char *line)
{
	t_list		*tmp;
	int			ret;
	int			i;

	i = 0;
	tmp = NULL;
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (line && *line && ret == 1)
			feed_tetris(&i, &tetris, line);
		else
		{
			feed_list(line, tetris, list, &tmp);
			i = 0;
		}
		if (ret == 0)
			return ;
	}
}
