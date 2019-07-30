##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	my_hunter.c



OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS =	-W -Wextra -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -l c_graph_prog

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
