#include "../includes/fillit.h"

int     main(int argc, char **argv)
{
        if (argc != 2)
        {
                ft_putstr("usage: ./fillit file.fillit\n");
                return (0);
        }
        else
                fillit(argv[1]);
        return 0;
}
