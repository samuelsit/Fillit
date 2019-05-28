/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:24:49 by ssitruk           #+#    #+#             */
/*   Updated: 2019/05/21 13:25:04 by ssitruk          ###   ########.fr       */
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

t_list			*clean_list(t_list *list);
void			put_error(void);
int				check_tet(int fd);
int				nb_tetriminos(char *file);
int				read_tetriminos(int fd);
void			four_filled(char **tet);
int				apply_on_list(t_list *list);
char			**create_map(int size_map);
char			**init_map(char **map, int size_map);
void			print_map(char **map);

typedef struct	s_tetris
{
	char **elem;
}				t_tetris;

#endif
