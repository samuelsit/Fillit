#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define EMPTY '.'
# define FILLED '#'
# define SIZE_TETRIS	4

void	put_error();
int		check_tet(int fd);
int     nbTetriminos(char *file);
int     readTetriminos(int fd);
void	four_filled(char **tet);
int		apply_on_list(t_list	*list);

typedef struct	s_tetris
{
	char **elem;
}		t_tetris;

#endif
