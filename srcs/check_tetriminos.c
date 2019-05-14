#include "../includes/fillit.h"

int     check_char(char *str, int l)
{
        int i;

        i = 0;
        if ((l % 5) != 0)
        {
                while (str[i] != '\0')
                {
                        if (str[i] != '.' && str[i] != '#')
                                return (0);
                        i++;
                }
        }
        return (1);
}

int     column(int c, int l)
{
        if ((l % 5) != 0)
        {
                if (c != 4)
                        return (0);
        }
        else
        {
                if (c != 0)
                        return (0);
        }
        return (1);
}

int     line(int l)
{
        if ((l % 5) == 0)
                return (1);
        return (0);
}

int     check_tet(int fd)
{
        int     ret;
        int     c;
        int     l;
        char    *line_tet;

        l = 1;
        while ((ret = get_next_line(fd, &line_tet)) > 0)
        {
                if (!(check_char(line_tet, l)))
                        return (0);
                c = ft_strlen(line_tet);
                if (!(column(c, l)))
                        return (0);
                l++;
        }
        if (!(line(l)))
                return (0);
        return (1);
}
