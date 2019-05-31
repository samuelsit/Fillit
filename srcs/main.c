/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:00:42 by ssitruk           #+#    #+#             */
/*   Updated: 2019/05/21 13:27:18 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		print_list(t_list *list)
{
	t_tetris	*tetris;
	int			i;

	i = 0;
	tetris = NULL;
	ft_putstr("\n----------\nPRINT LIST\n----------\n\n");
	while (list)
	{
		tetris = list->content;
		while (tetris->elem[i])
		{
			ft_putstr(tetris->elem[i]);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		list = list->next;
		i = 0;
	}
}

t_tetris	*new_tetris(void)
{
	t_tetris	*tetris;
	int			i;

	i = 0;
	if (!(tetris = malloc(sizeof(*tetris))))
		exit(0);
	if (!(tetris->elem = malloc(sizeof(char *) * (SIZE_TETRIS + 1))))
		exit(0);
	while (i < SIZE_TETRIS + 1)
	{
		if (!(tetris->elem[i] = malloc(sizeof(char) * (SIZE_TETRIS + 1))))
			exit(0);
		tetris->elem[i][SIZE_TETRIS] = '\0';
		i++;
	}
	tetris->elem[SIZE_TETRIS] = 0;
	tetris->width = SIZE_TETRIS;
	tetris->height = SIZE_TETRIS;
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
	tetris = new_tetris();
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (*line && ret == 1)
		{
			tetris->elem[i] = line;
			i++;
		}
		else
		{
			if (!(*list))
			{
				*list = ft_lstnew(tetris, sizeof(*tetris));
				tmp = *list;
			}
			else
			{
				tmp->next = ft_lstnew(tetris, sizeof(*tetris));
				tmp = tmp->next;
			}
			i = 0;
			tetris = new_tetris();
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
	t_map		*map;

	list = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <file>\n");
		return (0);
	}
	if ((fdcheck = open(argv[1], O_RDONLY)) < 0)
		return (0);
	if (!check_tet(fdcheck))
		return (0);
	close(fdcheck);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	build_list(fd, &list);
	close(fd);
	size_map = ft_sqrt(apply_on_list(list) * 4);
	map = create_map(size_map);
	print_map(map);
	list = clean_list(list);
	print_list(list);
	if ((map = backtracking(map, list, 0, 0)))
		print_map(map);
	else
		ft_putstr("NULL\n");
	return (0);
}
