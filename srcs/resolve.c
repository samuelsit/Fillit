

#include "../includes/fillit.h"

int	put_in_field(t_map *map, t_tetris *tetris, int x, int y)
{
	int i;
	int j;

	i = 0;
	if (tetris->width + x > map->size || tetris->height + y > map->size)
		return (0);
	while (tetris->elem[i])
	{
		j = 0;
		while (tetris->elem[i][j])
		{
			if (map->field[y + i][x + j] == FILLED && tetris->elem[i][j] == FILLED)
				return (0);
			map->field[y + i][x + j] = tetris->elem[i][j];
			j++;
		}
		i++;

	}
	return (1);
}

t_map	*backtracking(t_map *map, t_list *list, int x, int y)
{
	t_tetris *tetris;

	tetris = list->content;
	if (!tetris)
		return (map);
	if (x == map->size && y == map->size)
		return (NULL);
	if (!put_in_field(map, tetris, x, y))
		return (NULL);
	if (x == map->size)
		return (backtracking(map, list->next, 0, y + 1));
	else
		return (backtracking(map, list->next, x + 1, y));
}
