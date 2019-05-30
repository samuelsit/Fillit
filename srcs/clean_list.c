#include "../includes/fillit.h"

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

int		get_y(char **elem)
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

int		get_x(char **elem)
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

char		**new_malloc(char **elem, int x, int y)
{
	char	**new_elem;
	int		i;

	i = 0;
	new_elem = NULL;
	if (!(new_elem = (char **)malloc(sizeof(char*) * (y + 1))))
		return (NULL);
	while (i < y)
	{
		if (!(new_elem[i] = (char *)malloc(sizeof(char) * (x + 1))))
			return (NULL);
		new_elem[i][x] = '\0';
		i++;
	}
	new_elem[i] = NULL;
	new_elem = filled_new(elem, new_elem);
	return (new_elem);
}

t_list		*clean_list(t_list *list)
{
	t_tetris	*tetris;
	t_list		*tmp;
	int			x;
	int			y;

	x = 0;
	y = 0;
	tmp = list;
	tetris = NULL;
	while (tmp)
	{
		tetris = tmp->content;
		x = get_x(tetris->elem);
		y = get_y(tetris->elem);
		tetris->elem = new_malloc(tetris->elem, x, y);
		tmp = tmp->next;
	}
	return (list);
}
