
#include "../includes/fillit.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (i < map->size + 1)
	{
		free(map->field[i]);
		i++;
	}
	free(map->field);
	free(map);
	map = NULL;
}

void	free_tetris(t_tetris *tetris)
{
	int i;

	i = 0;
	if (!tetris)
		return ;
	while (i < tetris->height + 1)
	{
		free(tetris->elem[i]);
		i++;
	}
	free(tetris->elem);
	free(tetris);
	tetris = NULL;
}

void	free_list(t_list *list)
{
	t_list *tmp;

	if (list)
		tmp = list->next;
	while (list)
	{
		free_tetris(list->content);
		free(list);
		list = tmp;
		if (tmp)
			tmp = tmp->next;
	}
	list = NULL;
}