#include "../includes/fillit.h"
#include <stdio.h>

int		get_y_min(char **elem)
{
	int x;
	int y;
	int y_min;

	x = 0;
	y = 0;
	y_min = 0;
	while (x < 4)
	{
		while (elem[x][y] != '#' && elem[x][y] != '\0')
			y++;
		if (y == 4)
			y_min++;
		else
			return (y_min);
		y = 0;
		x++;
	}
	return (y_min);
}

int		get_x_min(char **elem)
{
	int x;
	int y;
	int x_min;

	x = 0;
	y = 0;
	x_min = 4;
	while (x < 4)
	{
		while (elem[x][y] != '#' && elem[x][y] != '\0')
			y++;
		x_min = (y < x_min) ? y : x_min;
		y = 0;
		x++;
	}
	return (x_min);
}

void			clean_list(t_list *list)
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
		//new_mall(tetris->elem);
		list = list->next;
	}
}
