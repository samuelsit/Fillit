
#include <stdio.h>
#include "../includes/fillit.h"

void	clear_field(t_map *map, char c)
{
	int i;
	int j;

	i = 0;
	while (map->field[i])
	{
		j = 0;
		while (map->field[i][j])
		{
			if (map->field[i][j] == c)
				map->field[i][j] = EMPTY;
			j++;
		}
		i++;
	}
	printf("CLEARED\n");
}

int	put_in_field(t_map *map, t_tetris *tetris, int x, int y)
{
	int i;
	int j;

	i = 0;
	if (tetris->width + x > map->size || tetris->height + y > map->size)
	{
		//printf("width=%d; height=%d; x=%d; y=%d; map_size=%d : ", tetris->width, tetris->height, x, y, map->size);
		//printf("size not ok\n");
		return (0);
	}
	while (tetris->elem[i])
	{
		j = 0;
		while (tetris->elem[i][j])
		{
			if (map->field[y + i][x + j] != EMPTY && tetris->elem[i][j] == FILLED)
			{
				printf("Obstrué map[%d][%d] : (%d) : map_size=%d\n", y, x, map->nb_tetris, map->size);
				clear_field(map, map->nb_tetris + 65);
				return (0);
			}
			if (tetris->elem[i][j] == FILLED)
			{
				printf("map[%d][%d] = %d\n", y + i, x + j, map->nb_tetris + 65);
				map->field[y + i][x + j] = (char)(map->nb_tetris + 65);
			}
			j++;
		}
		i++;
	}
	print_map(map);
	ft_putstr("\n");
	map->nb_tetris++;
	return (1);
}

t_map	*backtracking(t_map *map, t_list *list, int x, int y)
{
	t_map *ret;

	if (!list)
		return (map);
	//printf("TESTING : y=%d  ;x=%d : map_size=%d, nb_tetris=%d\n", y, x, map->size, map->nb_tetris);
	if (put_in_field(map, list->content, x, y))
	{
		printf("ENTER IN FIELD\n");
		list = list->next;
		x = 0;
		y = 0;
	}
	else
		x++;
	while (y < map->size)
	{
		while (x < map->size)
		{
			//printf("x=%d ; y=%d\n", x, y);
			if ((ret = backtracking(map, list, x, y)))
				return ret;
			x++;
		}
		y++;
		x = 0;
	}
	return (NULL);
}
