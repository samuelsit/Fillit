

#include "../includes/fillit.h"

int	backtrack(t_list *list, int final_size)
{
	char **field;
	int x;
	int y;

	x = 0;
	y = 0;
	field  = NULL; // remplacer par un field initialisé
	while (y < final_size)
	{
		while (x < final_size)
		{
			if (!(put_in_field(list->data->tetris, x, y)))
				// revenir en arriere;
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
