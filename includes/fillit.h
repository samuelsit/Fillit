/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:24:49 by ssitruk           #+#    #+#             */
/*   Updated: 2019/05/20 17:26:56 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void			put_error(void);
int				check_tet(int fd);
int				nb_tetriminos(char *file);
int				read_tetriminos(int fd);
void			four_filled(char **tet);
int				apply_on_list(t_list *list);

typedef struct	s_tetris
{
	char **elem;
}				t_tetris;

#endif
