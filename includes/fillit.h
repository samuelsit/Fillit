#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

void    fillit(char *file);
int     nbTetriminos(char *file);
int     readTetriminos(int fd);

#endif
