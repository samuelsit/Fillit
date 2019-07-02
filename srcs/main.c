/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:00:42 by ssitruk           #+#    #+#             */
/*   Updated: 2019/06/18 00:30:34 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetris	*new_tetris(int width, int height)
{
	t_tetris	*tetris;
	int			i;

	i = 0;
	if (!(tetris = malloc(sizeof(*tetris))))
		exit(0);
	if (!(tetris->elem = malloc(sizeof(char *) * (height + 1))))
		exit(0);
	while (i < height)
	{
		if (!(tetris->elem[i] = malloc(sizeof(char) * (width + 1))))
			exit(0);
		tetris->elem[i][width] = '\0';
		i++;
	}
	tetris->elem[height] = 0;
	tetris->width = width;
	tetris->height = height;
	return (tetris);
}

void		build_list(int fd, t_list **list)
{
	t_list		*tmp;
	t_tetris	*tetris;
	char		*line;
	int			ret;
	int			i;

	i = 0;
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (line && *line && ret == 1)
		{
			if ((i % 5) == 0)
				tetris = new_tetris(SIZE_TETRIS, SIZE_TETRIS);
			ft_strcpy(tetris->elem[i], line);
			free(line);
			line = NULL;
			i++;
		}
		else
		{
			if (line)
			{
				free(line);
				line = NULL;
			}
			if (!(*list))
			{
				*list = lst_tetris(tetris, sizeof(*tetris));
				tmp = *list;
			}
			else
			{
				tmp->next = lst_tetris(tetris, sizeof(*tetris));
				tmp = tmp->next;
			}
			i = 0;
		}
		if (ret == 0)
			return ;
	}
}

int			main(int argc, char **argv)
{
	t_list	*list;
	int		fdcheck;
	int		fd;
	int		size_map;
	t_map	*map;
	t_map	*res;

	list = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <file>\n");
		return (0);
	}
	if ((fdcheck = open(argv[1], O_RDONLY)) < 0)
		put_error();
	if (!check_tet(fdcheck))
		put_error();
	close(fdcheck);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		put_error();
	build_list(fd, &list);
	close(fd);
	size_map = ft_sqrt(apply_on_list(list) * 4);
	map = create_map(size_map);
	clean_list(&list);
	while (!(res = backtracking(map, list)))
	{
		size_map++;
		free_map(map);
		map = create_map(size_map);
	}
	print_map(res);
	free_map(res);
	free_list(list);
	return (0);
}
