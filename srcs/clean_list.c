#include "../includes/fillit.h"
#include <stdio.h>

int		filled_in_y(char *elem)
{
	int x;
	int nb;

	x = 0;
	nb = 0;
	while (elem[x])
	{
		if (elem[x] == FILLED)
			nb++;
		x++;
	}
	return (nb);
}

int		get_y_min(char **elem)
{
	int x;
	int y;
	int new_y;

	x = 0;
	y = 0;
	new_y = 0;
	while (elem[x])
	{
		new_y = filled_in_y(elem[x]) > new_y ? filled_in_y(elem[x]) : new_y;
		x++;
	}
	return (new_y);
}

int		get_x_min(char **elem)
{
	int x;
	int y;
	int new_x;

	x = 0;
	y = 0;
	new_x = 0;
	while (elem[x])
	{
		y = 0;
		while (elem[x][y])
		{
			if (elem[x][y] == FILLED)
			{
				new_x++;
				break;
			}
			y++;
		}
		x++;
	}
	return (new_x);
}

char		**new_mall(char **elem, int x, int y)
{
	int		i;
	char	**tetri;

	i = 0;
	if (!(tetri = ft_realloc(elem[i], x)))
		return (NULL);
	while (i <= y)
	{
		if (!(tetri[i] = ft_realloc(elem[i], y)))
			return (NULL);
		free(elem[i]);
	}
	free(elem);
	return (tetri);
}

t_list		*clean_list(t_list *list)
{
	t_tetris	*tetris;
	int		x;
	int		y;

	x = 0;
	y = 0;
	tetris = NULL;
	while (list)
	{
		tetris = list->content;
		x = get_x_min(tetris->elem);
		y = get_y_min(tetris->elem);
		printf("\nx = %d, y = %d\n", x, y);
		tetris->elem = new_mall(tetris->elem, x, y);
		list = list->next;
	}
	return (list);
}
