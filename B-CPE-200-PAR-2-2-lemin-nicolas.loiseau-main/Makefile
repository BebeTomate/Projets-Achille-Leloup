##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	lib/my/my_put_nbr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_strdup.c	\
		lib/my/my_struct_value.c	\
		linked_list/fill_str_list.c	\
		linked_list/display_list.c	\
		linked_list/free_list.c	\
		src/is_digit.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

LIB	=	-L -lmy

CFLAGS	=	-Wall -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	@rm -f libmy.a
	@ar rc libmy.a $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)
	@make clean

clean:
	@cd ./lib/my/ && rm -f *.o
	@cd ./linked_list && rm -f *.o
	@cd ./src && rm -f *.o
	@rm -f *.o
	@rm -f *#*
	@rm -f *~
	@rm -f libmy.a

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
