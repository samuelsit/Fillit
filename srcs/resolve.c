

#include "../includes/fillit.h"

int	put_in_field(char **field, char **tetris, int x, int y)
{
	int i;
	int j;

	i = 0;
	// Ici faire un if qui check si on va sortir du terrain avec ce tetris et ces coord
	while (tetris[i])
	{
		j = 0;
		while (tetris[i][j])
		{
			if (field[y + i][x + j] == FILLED && tetris[i][j] == FILLED)
				return (0);
			field[y + i][x + j] = tetris[i][j];
			j++;
		}
		i++;

	}
	return (1);
}

int	backtrack(t_list *list, int final_size, char **field)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < final_size)
	{
		while (x < final_size)
		{
			if (!(put_in_field(list->data->tetris, x, y)))
				;// revenir en arriere, jusqu'ou ? Récursivité ?
			else
			{
				list = list->next;
				if (!list)
					return (1);
				x++;
			}
		}
		y++;
	}
	return (0);
}
