#include "../includes/fillit.h"

int		get_width(char **elem)
{
	int height;
	int width;
	int new_width;

	height = 0;
	width = 0;
	new_width = 0;
	while (elem[height+1])
	{
		width = 0;
		while (elem[height+1][width])
		{
			if (elem[height][width] == FILLED && elem[height+1][width] != FILLED)
				new_width++;
			width++;
		}
		height++;
	}
	return (new_width);
}

int		get_height(char **elem)
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
				break;
			}
			width++;
		}
		height++;
	}
	return (new_height);
}

t_tetris		*new_malloc(t_tetris *tetris)
{
	int		i;
	int		first_filled_height;
	int		first_filled_width;

	i = 0;
	first_filled_height = len_height_filled(tetris->elem);
	first_filled_width = len_width_filled(tetris->elem);
	while (i < tetris->height)
	{
		if (!(tetris->elem[i] = (char *)ft_realloc(tetris->elem[i + first_filled_height], sizeof(char) * (tetris->width + 1), first_filled_width)))
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
		tetris->width = get_width(tetris->elem);
		ft_putnbr(tetris->width);
		tetris = new_malloc(tetris);
		tmp = tmp->next;
	}
	free(tmp);
	return (list);
}
