/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:00:42 by ssitruk           #+#    #+#             */
/*   Updated: 2019/07/03 14:19:11 by ssitruk          ###   ########.fr       */
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

int			do_open(char **argv)
{
	int fd;

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		put_error();
	return (fd);
}

void		fillit(t_list *list)
{
	t_map	*map;
	t_map	*res;
	int		size_map;

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
}

int			main(int argc, char **argv)
{
	t_list		*list;
	t_tetris	*tetris;
	char		*line;
	int			fd;

	list = NULL;
	tetris = NULL;
	line = NULL;
	check_error(argc);
	fd = do_open(argv);
	if (!check_tet(fd))
		put_error();
	close(fd);
	fd = do_open(argv);
	build_list(fd, &list, tetris, line);
	close(fd);
	fillit(list);
	return (0);
}
