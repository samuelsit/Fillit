#include "../includes/fillit.h"
#include <stdio.h>

int     nbTetriminos(char *file)
{
        int fd;

        fd = open(file, O_RDONLY);
        if (fd < 0)
                return (-1);
        else
                return (readTetriminos(fd));
        close(fd);
}

int     readTetriminos(int fd)
{
        int     ret;
        char    *line;
        int     nbLine;
        int     nbTetriminos;

        nbLine = 0;
        while ((ret = get_next_line(fd, &line)) > 0)
        {
                nbLine++;
                free(line);
        }
        nbTetriminos = nbLine / 4;
        return (nbTetriminos);
}
