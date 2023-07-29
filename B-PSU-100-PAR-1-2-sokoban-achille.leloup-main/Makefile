##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

CC	=	gcc

BASE_SRC	=	src/basic_function.c	\
				src/error_handling.c	\
				src/core_function.c	\
				src/player_move.c	\

SRC	=	$(BASE_SRC) \
		my_sokoban.c

SRC_TEST	=	$(BASE_SRC)	\
				tests/test.c

PATHH	=	-I include

OBJ	=	$(SRC:.c=.o)

OBJ_TEST	=	(SRC_TEST:.c=.o)

CFLAGS	=	-I include -g

NAME	=	my_sokoban

CRITERION	=	--coverage -lcriterion

H_NAME	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lncurses

clean:
	@rm -f $(OBJ)
	@rm -f src/*~
	@rm -f src/*#*
	@rm -f include/*~
	@rm -f include/*#*
	@rm -f *~
	@rm -f *#*
	@rm -f *gcno
	@rm -f *gcda
	@rm -f unit_tests
	@rm -f tests/*~
	@rm -f tests/*#*
	@rm -f web/*.css
	@rm -f web/*.html
	@rm -f web/web
	@rm -f coding-style-reports.log
	@rm -f libmy.a

fclean: clean
	@rm -f $(NAME)

re:	fclean all

unit_tests: $(NAME)
	$(CC) -o unit_tests $(SRC_TESTS) $(CRITERION)

tests_run: $(NAME)
	@make unit_tests
	@./unit_tests

gcovr:
	gcovr --exclude tests/ --html-details web/web
