SRC	=	srcs/main.c		\
		srcs/fillit.c		\
		srcs/readTetriminos.c

CC	=	gcc -g3

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
