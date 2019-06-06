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

typedef struct	s_map
{
	char	**field;
	int	size;
	int	nb_tetris;
}		t_map;

typedef struct	s_tetris
{
	char	**elem;
	int	occurence;
	int	width;
	int	height;
}		t_tetris;

int				len_width_filled(char **elem);
int				len_height_filled(char **elem);
t_list			*clean_list(t_list *list);
void			put_error(void);
int				check_tet(int fd);
int				nb_tetriminos(char *file);
int				read_tetriminos(int fd);
int			four_filled(char **tet);
int				apply_on_list(t_list *list);
void				print_list(t_list *list);
t_map			*create_map(int size);
char			**init_map(char **map, int size_map);
void			print_map(t_map *map);
t_map			*backtracking(t_map *map, t_list *list);
void			free_map(t_map *map);
void			free_tetris(t_tetris *map);
void			free_list(t_list *list);

#endif
