SRC	=	srcs/main.c		\
		srcs/check_tetriminos.c		\
		srcs/check_tetriminos2.c	\
		srcs/create_map.c	\
		srcs/clean_list.c	\
		srcs/clean_list2.c	\
		srcs/resolve.c		\
		srcs/free.c		\
		srcs/list_tetris.c	\
		srcs/build_list.c

CC	=	gcc

NAME	=	fillit

LIB	=	-Llibft -lft

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C libft
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
		$(RM) $(OBJ)
		make clean -C libft

fclean:		clean
		make fclean -C libft
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
