##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compiler
##

SRC	=	src/main.c \
		src/palindrome.c \
		src/error_handling.c \
		src/utils.c \

OBJS= $(SRC:.c=.o)

NAME=palindrome

CC = gcc

CFLAGS += -Wall -Wextra

CPPFLAGS += -I include/

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(SRC) -o $(NAME) $(CPPFLAGS)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
