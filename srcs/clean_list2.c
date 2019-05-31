#include "../includes/fillit.h"

int     first_width_filled(char **elem, int tmp)
{
    int height;
    int width;

    height = 0;
    while (elem[height])
	{
        width = 0;
        while (elem[height][width])
        {
            if (elem[height][width] == FILLED)
            {
                if (tmp == 0)
                    tmp = width;
                break;
            }
            width++;
        }
		height++;
	}
    return (tmp);
}

int     len_width_filled(char **elem)
{
    int height;
    int width;
    int tmp;

    tmp = 0;
    tmp = first_width_filled(elem, tmp);
    height = 0;
	while (elem[height])
	{
        width = 0;
        while (elem[height][width])
        {
            if (elem[height][width] == FILLED)
            {
                tmp = tmp > width ? width : tmp;
                break;
            }
            width++;
        }
		height++;
	}
	return (tmp);
}

int		len_height_filled(char **elem)
{
	int height;
    int width;

	height = 0;
	while (elem[height])
	{
        width = 0;
        while (elem[height][width])
        {
            if (elem[height][width] == FILLED)
                return (height);
            width++;
        }
		height++;
	}
	return (0);
}